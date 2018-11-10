#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел.
//Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A.
//Между собой числа разделены пробелом.
//
//Отсортируйте массив А по модулю и выведите его в стандартный поток.

// Ограничения
// 0 <= N <= 1000
// -1000000 <= A[i] <= 1000000

using std::cin;
using std::cout;
using std::vector;
using std::abs;
using std::endl;

int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(auto& n_ : nums){
    cin >> n_;
  }
  sort(nums.begin(), nums.end(), [](int& lhs, int& rhs){
    return abs(lhs) < abs(rhs);
  });
  for(auto& n : nums){
    cout << n << " ";
  }
  cout << endl;
  return 0;
}

