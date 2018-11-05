#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
// Между собой число и строки разделены пробелом.
//
// Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв,
// и выведите их в стандартный поток вывода.
//
// Ограничения
// 0 <= N <= 1000
// 1 <= |S| <= 15
// Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::tolower;
using std::lexicographical_compare;
using std::endl;

int main(){
  int n;
  cin >> n;
  vector<string> words(n);
  for(auto& w : words){
    cin >> w;
  }
  sort(words.begin(), words.end(), [](string& lhs, string& rhs){
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
                                   [](char& lhs, char& rhs){
        return tolower(lhs) < tolower(rhs);
    });
  });

  for(auto& n : words){
    cout << n << " ";
  }
  cout << endl;
  return 0;
}

