#include <iostream>
using namespace std;

// Шаблонные классы можно наследовать. Реализуйте шаблонную структуру ValueHolder с одним типовым
// параметром T, унаследованную от интерфейса ICloneable. Интерфейс ICloneable содержит всего
// один виртуальный метод ICloneable* clone() const, который должен вернуть указатель на копию
// объекта, на котором он был вызван (объект должен быть создан в куче). Шаблон ValueHolder,
// как говорит его название, хранит всего одно значение (назовите его data_) типа T (для типа
// T определен конструктор копирования). Не делайте поле data_ закрытым (поэтому в данном
// случае мы явно пишем, что ValueHolder должна быть структурой).

struct ICloneable
{
  virtual ICloneable* clone() const = 0;
  virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable
{
  ValueHolder(const T&  value)
      : data_(value) { }

  ValueHolder * clone() const
  {
    return new ValueHolder(data_);
  }

public:
  T  data_;
};

