#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::swap;

// Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v,
// в которой числа переставлены в обратном порядке.

vector<int> Reversed(const vector<int>& numbers){
  vector<int> result;
  for(size_t i = numbers.size(); i >= 1; i--){
    result.push_back(numbers[i - 1]);
  }
  return result;
}

