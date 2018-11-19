#pragma once
#include <cstdlib>
#include <stdexcept>

using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size)
    :size_(size), capacity_(size), data_(new T[size])
  {}
  SimpleVector(const SimpleVector& rhs){
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = new T[size_];
    copy(rhs.begin(), rhs.end(), begin());
  }

  void operator=(const SimpleVector& rhs) {
    if (rhs.size_ <= capacity_) {
      copy(rhs.begin(), rhs.end(), begin());
      size_ = rhs.size_;
    } else {
      SimpleVector<T> tmp(rhs);
      swap(tmp.data_, data_);
      swap(tmp.size_, size_);
      swap(tmp.capacity_, capacity_);
    }
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

  const T* begin() const{
    return data_;
  }

  const T* end() const {
    return data_ + size_;
  }

  size_t Size() const {
    return size_;
  }
  size_t Capacity() const {
    return capacity_;
  }

  void PushBack(T value){
    if(size_ == capacity_){
      capacity_ = capacity_ == 0 ? 1 : 2 * capacity_;
      T* new_data = new T[capacity_];
      move(begin(), end(), new_data);
      delete[] data_;
      data_ = new_data;
    }
    data_[size_++] = move(value);
  }

private:
  size_t size_ = 0;
  size_t capacity_ = 0;
  T* data_;
};

