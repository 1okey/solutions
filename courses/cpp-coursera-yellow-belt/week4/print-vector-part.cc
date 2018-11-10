#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers, выполняющую поиск
// первого отрицательного числа в нём и выводящую в стандартный вывод все числа, расположенные
// левее найденного, в обратном порядке. Если вектор не содержит отрицательных чисел, выведите
// все числа в обратном порядке.

void PrintVectorPart(const vector<int>& numbers){
  auto it = find_if(numbers.begin(), numbers.end(),
                    [](const int& n){
    return n < 0;
  });

  for (; it != numbers.begin(); ) {
    cout << *(--it) << " ";
  }
  cout << endl;
}

