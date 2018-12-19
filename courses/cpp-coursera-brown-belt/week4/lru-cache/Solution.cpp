#include "Common.h"
#include <mutex>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class LruCache : public ICache {
public:
  LruCache(shared_ptr<IBooksUnpacker> books_unpacker, size_t max_memory)
    : unpacker_(books_unpacker), size_(max_memory) {}

  BookPtr GetBook(const string& book_name) override {
    {
      lock_guard<mutex> guard(n);
      auto it = table_.find(book_name);
      if(it != table_.end()){
        rangs_[it->first] = ++max_rang;
        return it->second;
      }
    }

    auto book = unpacker_->UnpackBook(book_name);
    size_t book_size = book->GetContent().size();
    {
      lock_guard<mutex> guard(n);

      if(book_size > size_ && !FreeCache(book_size)){
        return nullptr;
      }
    }

    {
      lock_guard<mutex> guard(n);
      rangs_.insert({book_name, ++max_rang});
      table_.insert({book_name, move(book)});
      size_ -= book_size;
      return table_.find(book_name)->second;
    }
  }
  virtual ~LruCache() override {}
private:
  bool FreeCache(size_t book_size){

    while(book_size > size_){
      auto it = min_element(rangs_.begin(), rangs_.end(),
                            [](const auto& lhs, const auto& rhs){
        return lhs.second < rhs.second;
      });
      if(it == rangs_.end()){
        return false;
      }
      string book_to_remove = it->first;
      auto book = table_.find(book_to_remove);

      size_ += book->second->GetContent().size();
      table_.erase(book_to_remove);
      rangs_.erase(book_to_remove);
    }
    return true;
  }

  mutex n;
  shared_ptr<IBooksUnpacker> unpacker_;
  size_t size_;
  uint64_t max_rang = 1;
  unordered_map<string, uint64_t> rangs_;
  unordered_map<string, BookPtr> table_;
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
    ) {
  return make_unique<LruCache>(books_unpacker, settings.max_memory);
}
