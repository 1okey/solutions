#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего
// арифметического за все N дней.

// Гарантируется, что среднее арифметическое значений температуры является целым числом.

// -- Формат ввода
// Вводится число N, затем N неотрицательных целых чисел — значения температуры
// в 0-й, 1-й, ... (N−1)-й день.

// -- Формат вывода
// Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
// Затем K целых чисел — номера этих дней.

int main(){
  size_t n, sum = 0;
  cin >> n;
  vector<size_t> temps(n);
  for(size_t& t: temps){
    cin >> t;
    sum += t;
  }

  int t_mean = sum / n;
  size_t i = 0;
  vector<size_t> above_average;
  for(size_t& t: temps){
    if(t > t_mean){
      above_average.push_back(i);
    }
    i++;
  }

  cout << above_average.size() << '\n';
  for(size_t& t: above_average){
    cout << t << " " ;
  }
  cout << endl;
  return 0;
}

