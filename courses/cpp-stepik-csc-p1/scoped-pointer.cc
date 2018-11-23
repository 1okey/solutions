// Помните иерархию Expression, которую мы разрабатывали на четвёртой неделе? Реализуйте ScopedPtr,
// который будет работать с указателями на базовый класс Expression. В этом задании вам требуется
// реализовать методы get, release и reset, операторы * и -> так, как это было описано в предыдущем
// степе. А также реализуйте конструктор ScopedPtr от указателя на Expression.

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
  // реализуйте следующие методы:
  //
  // explicit ScopedPtr(Expression *ptr = 0)
  // ~ScopedPtr()
  // Expression* get() const
  // Expression* release()
  // void reset(Expression *ptr = 0)
  // Expression& operator*() const
  // Expression* operator->() const
  explicit ScopedPtr(Expression *ptr = nullptr): ptr_(ptr) {}
  Expression * get() const {
    return ptr_;
  }
  Expression * release() {
    Expression * e = ptr_;
    ptr_ = nullptr;
    return e;
  }
  void reset (Expression *ptr = nullptr){
    delete ptr_;
    ptr_ = ptr;
  }
  Expression& operator*() const {
    return (*ptr_);
  }
  Expression* operator->() const {
    return ptr_;
  }
  ~ScopedPtr(){
    delete ptr_;
  }

private:
  ScopedPtr(const ScopedPtr&);
  ScopedPtr& operator=(const ScopedPtr&);

  Expression *ptr_;
};

