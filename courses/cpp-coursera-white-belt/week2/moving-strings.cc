#include <iostream>
#include <vector>

using std::vector;
using std::string;
// Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
// и дописывает все строки из первого вектора в конец второго.
// После выполнения функции вектор source должен оказаться пустым.

// Чтобы очистить содержимое вектора, надо вызвать у него метод clear:

void MoveStrings(vector<string>& source, vector<string>& result){
  for(string& word: source){
    result.push_back(word);
  }
  source.clear();
}

