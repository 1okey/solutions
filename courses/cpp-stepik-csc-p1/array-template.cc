#include <cstddef>

// Реализуйте шаблонную версию класса Array. Список всех операций,
// которые должен поддерживать класс Array, приведен в шаблоне кода.

template <typename T>
class Array
{
public:
  Array(size_t size, const T& value = T()) {
    size_ = size;
    data_ = (T*) new char[size_*sizeof(T)];
    for (size_t i = 0; i != size_; ++i) {
      new (data_ + i) T(value);
    }
  }

  Array() {
    size_ = 0;
    data_ = (T*) new char[size_*sizeof(T)];
  }


  Array(const Array & a) {
    size_ = a.size();
    data_ = (T*) new char[a.size()*sizeof(T)];

    for (size_t i = 0; i != size_; ++i) {
      new (data_ + i) T(a.data_[i]);
    }
  }

  ~Array() {
    for (size_t i = 0; i < size_; ++i) {
      data_[i].~T();
    }
    delete [] (char*) data_;
  }

  Array & operator=(Array const& a) {
    if (this != &a) {
      for (size_t i = 0; i < size_; ++i) {
        data_[i].~T();
      }
      delete [] (char*) data_;

      size_ = a.size();
      data_ = (T*) new char[a.size()*sizeof(T)];

      for (size_t i = 0; i != size_; ++i) {
        new (data_ + i) T(a.data_[i]);
      }
    }
    return *this;
  }

  size_t size() const {
    return size_;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  const T& operator[](size_t index) const {
    return data_[index];
  }

private:
  size_t size_;
  T * data_;
};

