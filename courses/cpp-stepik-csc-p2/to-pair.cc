#include <tuple>
#include <utility>

using namespace std;

// Напишите шаблонную функцию to_pair, которая принимает произвольный std::tuple
// и два индекса внутри и возвращает std::pair, содержащий элементы переданного
// std::tuple с соответствующими индексами.

// Замечание: реализация должна работать в рамках стандарта C++11.

template<size_t first, size_t second, typename Tup>
auto to_pair(Tup tup) -> decltype(make_pair(get<first>(tup), get<second>(tup)))
{
  return make_pair(get<first>(tup), get<second>(tup));
}
