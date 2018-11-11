#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size)
    :size_(size), capacity_(size), data_(new T[size])
  {

  }
  ~SimpleVector(){
    delete [] data_;
  }

  T& operator[](size_t index){
    if(index >= size_){
      throw out_of_range("");
    }
    else {
      return data_[index];
    }
  }

  T* begin(){
    return data_;
  }

  T* end(){
    return data_ + size_;
  }

  size_t Size() const {
    return size_;
  }
  size_t Capacity() const {
    return capacity_;
  }

  void PushBack(const T& value){
    if(size_ == capacity_){
      capacity_ = capacity_ == 0 ? 1 : 2 * capacity_;
      T* new_data = new T[capacity_];
      copy(begin(), end(), new_data);
      delete[] data_;
      data_ = new_data;
    }
    data_[size_++] = value;
  }

private:
  size_t size_ = 0;
  size_t capacity_ = 0;
  T* data_;
};



void TestConstruction() {
  SimpleVector<int> empty;
  ASSERT_EQUAL(empty.Size(), 0u);
  ASSERT_EQUAL(empty.Capacity(), 0u);
  ASSERT(empty.begin() == empty.end());

  SimpleVector<string> five_strings(5);
  ASSERT_EQUAL(five_strings.Size(), 5u);
  ASSERT(five_strings.Size() <= five_strings.Capacity());
  for (auto& item : five_strings) {
    ASSERT(item.empty());
  }
  five_strings[2] = "Hello";
  ASSERT_EQUAL(five_strings[2], "Hello");
}

void TestPushBack() {
  SimpleVector<int> v;
  for (int i = 10; i >= 1; --i) {
    v.PushBack(i);
    ASSERT(v.Size() <= v.Capacity());
  }
  sort(begin(v), end(v));

  const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQUAL(v.Size(), expected.size());
  ASSERT(equal(begin(v), end(v), begin(expected)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestConstruction);
  RUN_TEST(tr, TestPushBack);
  return 0;
}

