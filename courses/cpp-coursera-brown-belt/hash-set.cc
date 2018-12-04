#include "test_runner.h"

#include <forward_list>
#include <iterator>
#include <algorithm>

using namespace std;

// Требования:
//
// - В любой момент времени в вашей хеш-таблице должно быть ровно numBuckets корзин.
// Рехеширование выполнять не нужно.
// - Метод Add не должен менять содержимое таблицы, если элемент, равный данному, уже есть в таблице,
// - Метод Has должен возвращать true тогда и только тогда, когда элемент, равный данному, есть в
// таблице,
// - Метод Erase должен стирать элемент, равный данному, из таблицы, если он там есть, в противном
// случае он не должен менять содержимое таблицы,
// - Метод GetBucket должен возвращать ссылку на бакет, который содержал бы данный элемент, вне
// зависимости от того, есть он в таблице или нет.

template <typename Type, typename Hasher = hash<Type>>
class HashSet {
public:
  using BucketList = forward_list<Type>;

public:
  explicit HashSet(size_t num_buckets = 1, const Hasher& hasher = {})
    :_M_data(num_buckets), _M_hasher(hasher), _M_bucket_size(num_buckets)
  {}

  void Add(const Type& value){
    auto& bucket = _M_data[GetIndex(value)];
    auto it = find(begin(bucket), end(bucket), value);

    if (it == bucket.end()) {
      bucket.push_front(value);
    }
  }

  bool Has(const Type& value) const {
    const BucketList& bucket = _M_data[GetIndex(value)];
    return find(bucket.begin(), bucket.end(), value) != bucket.end();
  }

  void Erase(const Type& value){
    _M_data[GetIndex(value)].remove(value);
  }

  const BucketList& GetBucket(const Type& value) const {
    return _M_data[GetIndex(value)];
  }
private:
  size_t GetIndex(const Type& value) const {
    size_t result = _M_hasher(value) % _M_bucket_size;
    return result;
  }

  vector<BucketList> _M_data;
  Hasher _M_hasher;
  size_t _M_bucket_size;
};

struct IntHasher {
  size_t operator()(int value) const {
    return value;
  }
};

struct TestValue {
  int value;

  bool operator==(TestValue other) const {
    return value / 2 == other.value / 2;
  }
};

struct TestValueHasher {
  size_t operator()(TestValue value) const {
    return value.value / 2;
  }
};

void TestSmoke() {
  HashSet<int, IntHasher> hash_set(2);
  hash_set.Add(3);
  hash_set.Add(4);

  ASSERT(hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(!hash_set.Has(5));

  hash_set.Erase(3);

  ASSERT(!hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(!hash_set.Has(5));

  hash_set.Add(3);
  hash_set.Add(5);

  ASSERT(hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(hash_set.Has(5));
}

void TestEmpty() {
  HashSet<int, IntHasher> hash_set(10);
  for (int value = 0; value < 10000; ++value) {
    ASSERT(!hash_set.Has(value));
  }
}

void TestIdempotency() {
  HashSet<int, IntHasher> hash_set(10);
  hash_set.Add(5);
  ASSERT(hash_set.Has(5));
  hash_set.Add(5);
  ASSERT(hash_set.Has(5));
  hash_set.Erase(5);
  ASSERT(!hash_set.Has(5));
  hash_set.Erase(5);
  ASSERT(!hash_set.Has(5));
}

void TestEquivalence() {
  HashSet<TestValue, TestValueHasher> hash_set(10);
  hash_set.Add(TestValue{2});
  hash_set.Add(TestValue{3});

  ASSERT(hash_set.Has(TestValue{2}));
  ASSERT(hash_set.Has(TestValue{3}));

  const auto& bucket = hash_set.GetBucket(TestValue{2});
  const auto& three_bucket = hash_set.GetBucket(TestValue{3});
  ASSERT_EQUAL(&bucket, &three_bucket);

  ASSERT_EQUAL(1, distance(begin(bucket), end(bucket)));
  ASSERT_EQUAL(2, bucket.front().value);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSmoke);
  RUN_TEST(tr, TestEmpty);
  RUN_TEST(tr, TestIdempotency);
  RUN_TEST(tr, TestEquivalence);
  return 0;
}

