#include <iostream>
#include <set>
#include <string>
// Дан набор строк. Найдите количество уникальных строк в этом наборе.
//
// Формат ввода
// Сначала вводится количество строк N, затем — сами N строк, разделённые пробелом.
// Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.
//
// Формат вывода
// Выведите единственное целое число — количество уникальных строк в данном наборе.

using std::cin;
using std::cout;
using std::set;
using std::string;
using std::endl;

int main(){
  size_t n;
  string word;
  set<string> words;
  cin >> n;
  for(; n > 0; n--){
    cin >> word;
    words.insert(word);
  }
  cout << words.size();
  return 0;
}

