#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::swap;
// Реализуйте функцию void Reverse(vector<int>& v),
// которая переставляет элементы вектора в обратном порядке.

void Reverse(vector<int>& numbers){
  for(size_t i = 0; i < numbers.size() / 2; i++){
    swap(numbers[i], numbers[numbers.size() - i - 1]);
  }
}

