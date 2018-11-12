#pragma once

#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0): size_(a_size){
    if(size_ > N){
      throw invalid_argument("Size can't be bigger than allocated size");
    }
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  const T& operator[](size_t index) const {
    return data_[index];
  }

  auto begin() {
    return data_.begin();
  }

  auto end() {
    return data_.begin() + size_;
  }

  auto begin() const {
    return data_.begin();
  }

  auto end() const {
    return data_.begin() + size_;
  }

  size_t Size() const {
    return size_;
  }

  size_t Capacity() const {
    return N;
  }

  void PushBack(const T& value){
    if(size_ >= N){
      throw overflow_error("Can't add more items, StackedVector for full");
    } else {
      data_[size_++] = value;
    }
  }

  T PopBack(){
    if(size_ == 0){
      throw underflow_error("Can't remove elements from empty StackedVector");
    } else {
      return data_[--size_];
    }
  }

private:
  array<T, N> data_;
  size_t size_ = 0;
};


void TestConstruction() {
  StackVector<int, 10> v;
  ASSERT_EQUAL(v.Size(), 0u);
  ASSERT_EQUAL(v.Capacity(), 10u);

  StackVector<int, 8> u(5);
  ASSERT_EQUAL(u.Size(), 5u);
  ASSERT_EQUAL(u.Capacity(), 8u);

  try {
    StackVector<int, 10> u(50);
    Assert(false, "Expect invalid_argument for too large size");
  } catch (invalid_argument&) {
  } catch (...) {
    Assert(false, "Unexpected exception for too large size");
  }
}

void TestPushBack() {
  StackVector<int, 5> v;
  for (size_t i = 0; i < v.Capacity(); ++i) {
    v.PushBack(i);
  }

  try {
    v.PushBack(0);
    Assert(false, "Expect overflow_error for PushBack in full vector");
  } catch (overflow_error&) {
  } catch (...) {
    Assert(false, "Unexpected exception for PushBack in full vector");
  }
}

void TestPopBack() {
  StackVector<int, 5> v;
  for (size_t i = 1; i <= v.Capacity(); ++i) {
    v.PushBack(i);
  }
  for (int i = v.Size(); i > 0; --i) {
    ASSERT_EQUAL(v.PopBack(), i);
  }

  try {
    v.PopBack();
    Assert(false, "Expect underflow_error for PopBack from empty vector");
  } catch (underflow_error&) {
  } catch (...) {
    Assert(false, "Unexpected exception for PopBack from empty vector");
  }
}

int main() {
  {
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestPushBack);
    RUN_TEST(tr, TestPopBack);
  }

  cerr << "Running benchmark..." << endl;
  const size_t max_size = 2500;

  default_random_engine re;
  uniform_int_distribution<int> value_gen(1, max_size);

  vector<vector<int>> test_data(50000);
  for (auto& cur_vec : test_data) {
    cur_vec.resize(value_gen(re));
    for (int& x : cur_vec) {
      x = value_gen(re);
    }
  }

  {
    LOG_DURATION("vector w/o reserve");
    for (auto& cur_vec : test_data) {
      vector<int> v;
      for (int x : cur_vec) {
        v.push_back(x);
      }
    }
  }
  {
    LOG_DURATION("vector with reserve");
    for (auto& cur_vec : test_data) {
      vector<int> v;
      v.reserve(cur_vec.size());
      for (int x : cur_vec) {
        v.push_back(x);
      }
    }
  }
  {
    LOG_DURATION("StackVector");
    for (auto& cur_vec : test_data) {
      StackVector<int, max_size> v;
      for (int x : cur_vec) {
        v.PushBack(x);
      }
    }
  }
  cerr << "Done" << endl;
}

