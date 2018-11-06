#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// В первой строке файла input.txt записаны два числа N и M. Далее в файле находится
// таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values).
// Такой формат часто используется для текстового представления таблиц с данными: в файле
// несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.
// Ваша задача — вывести данные на экран в виде таблицы, размер ячейки которой равен 10,
// соседние ячейки отделены друг от друга пробелом. После последней ячейки пробела быть не
// должно. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой
// из ячеек — целое число.

using namespace std;

int main() {
  ifstream input("input.txt");

  int n, m;
  input >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      input >> x;
      input.ignore(1);
      cout << setw(10) << x;
      if (j != m - 1) {
        cout << " ";
      }
    }
    if (i != n - 1) {
      cout << endl;
    }
  }

  return 0;
}

