#include <vector>
#include <stdexcept>
#include <string>
#include <cstddef>

using namespace std;

template <typename T>
class Deque {
public:
  Deque() = default;
  T& operator[](size_t index){
    return index < head.size() ? head[head.size() - index - 1] : tail[index - head.size()];
  }

  const T& operator[](size_t index) const {
    return index < head.size() ? head[head.size() - index - 1] : tail[index - head.size()];
  }

  T& At(size_t index) {
    if(index >= Size()){
      throw out_of_range("No item at" + to_string(index));
    }
    return (*this)[index];
  }
  const T& At(size_t index) const {
    if(index >= Size()){
      throw out_of_range("No item at" + to_string(index));
    }
    return (*this)[index];
  }

  T& Front() {
    return head.empty() ? tail.front() : head.back();
  }

  const T& Front() const {
    return head.empty() ? tail.front() : head.back();
  }

  T& Back() {
    return tail.empty() ? head.front() : tail.back();
  }

  const T& Back() const {
    return tail.empty() ? head.front() : tail.back();
  }

  bool Empty() const {
    return tail.empty() && head.empty();
  }

  size_t Size() const {
    return tail.size() + head.size();
  }

  void PushBack(const T& item){
    tail.push_back(item);
  }

  void PushFront(const T& item){
    head.push_back(item);
  }

  void Clear() {
    head.clear();
    tail.clear();
  }

private:
  vector<T> head, tail;
};

