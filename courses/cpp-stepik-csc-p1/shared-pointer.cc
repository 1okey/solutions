#include <cstdlib>
#include <algorithm>

// Реализуйте класс SharedPtr как описано ранее. Задание немного сложнее, чем кажется на первый
// взгляд. Уделите особое внимание "граничным случаям" — нулевой указатель, присваивание самому
// себе, вызов reset на нулевом SharedPtr и прочее.

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
  explicit SharedPtr(Expression *ptr = 0) :
    ptr_(ptr), counter_(0)
  {
    if (ptr_){
      counter_ = new size_t(1);
    }
  }

  SharedPtr(const SharedPtr &other)
    : ptr_(other.ptr_), counter_(other.counter_)
  {
    if (ptr_) {
      ++(*counter_);
    }
  }

  ~SharedPtr()
  {
    if (ptr_ && --(*counter_) == 0)
    {
      delete ptr_;
      delete counter_;
    }
  }

  SharedPtr& operator=(const SharedPtr &other)
  {
    if (this != &other) {
      SharedPtr(other).swap(*this);
    }
    return *this;
  }

  void reset(Expression *other = 0) {
    SharedPtr(other).swap(*this);
  }

  void swap(SharedPtr &other)
  {
    std::swap(ptr_, other.ptr_);
    std::swap(counter_, other.counter_);
  }

  Expression* get() const { return ptr_; }

  Expression& operator*() const { return *ptr_; }

  Expression* operator->() const { return ptr_; }

private:
  Expression *ptr_;
  size_t *counter_;
};


int main(){
  return 0;
}

