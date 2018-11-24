#include <cstddef>

// Реализуйте шаблонную функцию minimum, которая находит минимальный элемент, который 
// хранится в экземпляре шаблонного класса Array, при этом типовой параметр шаблона 
// Array может быть произвольным. Чтобы сравнивать объекты произвольного типа, на вход
// функции также будет передаваться компаратор, в качестве компаратора может выступать
// функция или объект класса с перегруженным оператором "()".

template <typename T>
class Array
{
public:
  explicit Array(size_t size = 0, const T& value = T());
  Array(const Array& other);
  ~Array();
  Array& operator=(Array other);
  void swap(Array &other);
  size_t size() const;
  T& operator[](size_t idx);
  const T& operator[](size_t idx) const;

private:
  size_t size_;
  T *data_;
};

template <typename T, typename C>
T minimum(const Array<T> & array, C comparator) {
  T minimum = array[0];
  for (int i = 0; i < array.size(); ++i) {
    if (!comparator(minimum, array[i])) {
      minimum = array[i];
    }
  }
  return minimum;
}

