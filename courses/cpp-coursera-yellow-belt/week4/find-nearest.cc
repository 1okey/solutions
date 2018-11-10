#include <set>
#include <iterator>

using namespace std;

// Напишите функцию FindNearestElement, для множества целых чисел numbers и данного
// числа border возвращающую итератор на элемент множества, ближайший к border.
// Если ближайших элементов несколько, верните итератор на наименьший из них.

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

  auto l_bound = numbers.lower_bound(border);
  if(l_bound == numbers.begin()){
    return l_bound;
  }

  auto prev_l_bound = prev(l_bound);
  if(l_bound == numbers.end()){
    return prev_l_bound;
  }

  return *l_bound - border >= border - *prev_l_bound
      ? prev_l_bound
      : l_bound;
}

