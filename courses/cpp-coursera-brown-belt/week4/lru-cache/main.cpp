#include "Common.h"
#include "test_runner.h"

#include <atomic>
#include <future>
#include <numeric>
#include <random>
#include <sstream>

using namespace std;

// Данная реализация интерфейса IBook позволяет отследить объём памяти, в данный
// момент занимаемый всеми загруженными книгами. Для тестирования своей
// программы вы можете написать другую реализацию, которая позволит также
// убедиться, что из кэша выгружаются в первую очередь наименее используемые
// элементы. Собственно, тестирующая система курсеры имеет как раз более
// продвинутую реализацию.
class Book : public IBook {
public:
  Book(
      string name,
      string content,
      atomic<size_t>& memory_used_by_books
  )
    : name_(move(name))
    , content_(move(content))
    , memory_used_by_books_(memory_used_by_books)
  {
    memory_used_by_books_ += content_.size();
  }

  ~Book() {
    memory_used_by_books_ -= content_.size();
  }

  const string& GetName() const override {
    return name_;
  }

  const string& GetContent() const override {
    return content_;
  }

private:
  string name_;
  string content_;
  atomic<size_t>& memory_used_by_books_;
};

// Данная реализация интерфейса IBooksUnpacker позволяет отследить объём памяти,
// в данный момент занимаемый всеми загруженными книгами и запросить количество
// обращений к методу UnpackBook(). Для тестирования своей программы вы можете
// написать другую реализацию. Собственно, тестирующая система курсеры имеет как
// раз более продвинутую реализацию.
class BooksUnpacker : public IBooksUnpacker {
public:
  unique_ptr<IBook> UnpackBook(const string& book_name) override {
    ++unpacked_books_count_;
    return make_unique<Book>(
      book_name,
      "Dummy content of the book " + book_name,
      memory_used_by_books_
    );
  }

  size_t GetMemoryUsedByBooks() const {
    return memory_used_by_books_;
  }

  int GetUnpackedBooksCount() const {
    return unpacked_books_count_;
  }

private:
  // Шаблонный класс atomic позволяет безопасно использовать скалярный тип из
  // нескольких потоков. В противном случае у нас было бы состояние гонки.
  atomic<size_t> memory_used_by_books_ = 0;
  atomic<int> unpacked_books_count_ = 0;
};

// Названия книг для локального тестирования. В тестирующей системе курсеры
// будет другой набор, намного больше.
const string book_names[] = {
  "Sherlock Holmes",
  "Don Quixote",
  "Harry Potter",
  "A Tale of Two Cities",
  "The Lord of the Rings",
  "Le Petit Prince",
  "Alice in Wonderland",
  "Dream of the Red Chamber",
  "And Then There Were None",
  "The Hobbit"
};


// Для удобства локального тестирования, считаем все книги в память.
const unordered_map<string, unique_ptr<IBook>> library = [] {
  unordered_map<string, unique_ptr<IBook>> library;
  BooksUnpacker unpacker;
  for (const auto& book_name : book_names) {
    library[book_name] = unpacker.UnpackBook(book_name);
  }
  return library;
}();


const size_t library_size = accumulate(
    library.begin(), library.end(),
    size_t(0),
    [](size_t x, const auto& item) {
      return x + item.second->GetContent().size();
    }
);


void TestUnpacker() {
  BooksUnpacker unpacker;
  for (const auto& book_name : book_names) {
    auto book = unpacker.UnpackBook(book_name);
    ASSERT_EQUAL(book->GetName(), book_name);
  }
}


void TestMaxMemory() {
  auto unpacker = make_shared<BooksUnpacker>();
  ICache::Settings settings;
  settings.max_memory = library_size / 2;
  auto cache = MakeCache(unpacker, settings);

  for (const auto& [name, book] : library) {
    cache->GetBook(name);
    ASSERT(unpacker->GetMemoryUsedByBooks() <= settings.max_memory);
  }
}


void TestCaching() {
  auto unpacker = make_shared<BooksUnpacker>();
  ICache::Settings settings;
  settings.max_memory = library_size;
  auto cache = MakeCache(unpacker, settings);

  // Если запрашивать одну и ту же книгу подряд, то она определённо должна
  // возвращаться из кэша. Заметьте, что этого простого теста вовсе
  // недостаточно, чтобы полностью проверить правильность реализации стратегии
  // замещения элементов в кэше. Для этих целей можете написать тест
  // самостоятельно.
  cache->GetBook(book_names[0]);
  cache->GetBook(book_names[0]);
  cache->GetBook(book_names[0]);
  ASSERT_EQUAL(unpacker->GetUnpackedBooksCount(), 1);
}


void TestSmallCache() {
  auto unpacker = make_shared<BooksUnpacker>();
  ICache::Settings settings;
  settings.max_memory =
      unpacker->UnpackBook(book_names[0])->GetContent().size() - 1;
  auto cache = MakeCache(unpacker, settings);

  cache->GetBook(book_names[0]);
  ASSERT_EQUAL(unpacker->GetMemoryUsedByBooks(), size_t(0));
}


void TestAsync() {
  static const int tasks_count = 10;
  static const int trials_count = 10000;

  auto unpacker = make_shared<BooksUnpacker>();
  ICache::Settings settings;
  settings.max_memory = library_size - 1;
  auto cache = MakeCache(unpacker, settings);

  vector<future<void>> tasks;

  for (int task_num = 0; task_num < tasks_count; ++task_num) {
    tasks.push_back(async([&cache, task_num] {
      default_random_engine gen;
      uniform_int_distribution<size_t> dis(0, size(book_names) - 1);
      for (int i = 0; i < trials_count; ++i) {
        const auto& book_name = book_names[dis(gen)];
        ASSERT_EQUAL(
            cache->GetBook(book_name)->GetContent(),
            library.find(book_name)->second->GetContent()
        );
      }
      stringstream ss;
      ss << "Task #" << task_num << " completed\n";
      cout << ss.str();
    }));
  }

  // вызов метода get пробрасывает исключения в основной поток
  for (auto& task : tasks) {
    task.get();
  }
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUnpacker);
  RUN_TEST(tr, TestMaxMemory);
  RUN_TEST(tr, TestCaching);
  RUN_TEST(tr, TestSmallCache);
  RUN_TEST(tr, TestAsync);
  return 0;
}
