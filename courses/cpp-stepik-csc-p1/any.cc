#include <iostream>

// В первом уроке вы реализовали простой шаблон ValueHolder, в этом задании мы используем его
// чтобы написать класс Any (интересно, что не шаблонный), который позволяет хранить значения
// любого типа! Например, вы сможете  создать массив объектов типа Any, и сохранять в них int-ы,
// double-ы или даже объекты Array. Подробности в шаблоне кода.
//
// Hint: в нешаблонном классе Any могут быть шаблонные методы, например, шаблонный конструктор.
//
// Для реализации вам может потребоваться оператор dynamic_cast.
//
// С++ предоставляет и более простой способ узнать конкретный класс по указателю (или ссылке) на
// базовый класс. Для этого можно использовать оператор dynamic_cast. Например, если у вас есть
// указатель Expression *, и вы хотите узнать, указывает ли этот указатель на самом деле на объект
// Number, то сделать это можно так:

// Эти классы реализовывать заново не нужно
struct ICloneable;

// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
template <typename T>
struct ValueHolder;

class Any {
  
public:
  
  Any() : value_(0) {}
  
  template <typename T>
  explicit Any(T value) {
    value_ = new ValueHolder<T>(value);
  }
  
  ~Any() {
    delete value_;
  }
  
  Any(const Any & other) {
    if (other.value_) {
      value_ = other.value_->clone();
    } else {
      value_ = 0;
    }
  }
  
  Any & operator=(const Any & other) {
    if (this != &other) {
      delete value_;
      if (other.value_) {
        value_ = other.value_->clone();
      } else {
        value_=  0;
      }
      return *this;
    }
  }
  
  template <typename T>
  Any & operator=(T value) {
    delete value_;
    value_ = new ValueHolder<T>(value);
  }
  
  template <typename T>
  T * cast() {
    ValueHolder<T> * valueHolder = dynamic_cast<ValueHolder<T> *>(value_);
    if (valueHolder) {
      return &valueHolder->data_;
    } else {
      return 0;
    }
  }
  
private:
  ICloneable * value_;
};

