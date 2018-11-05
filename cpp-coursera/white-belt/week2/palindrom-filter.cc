#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
// Напишите функцию, которая

// - называется PalindromFilter
// - возвращает vector<string>
// - принимает vector<string> words и int minLength и возвращает все строки из вектора words,
// которые являются палиндромами и имеют длину не меньше minLength

// Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

bool IsPalindrom(const std::string& word){
  for(size_t i = 0;i < word.size() / 2; i++){
    if(word[i] != word[word.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

vector<string> PalindromFilter(vector<string>& words, int min_length){
  vector<string> result;
  for(string& word: words){
    if(word.length() >= min_length && IsPalindrom(word)){
      result.push_back(word);
    }
  }
  return result;
}

