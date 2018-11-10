#include <iostream>
#include <set>
#include <string>
#include <map>
#include <utility>

// Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string>
// и возвращающую множество значений этого словаря:

using std::cin;
using std::cout;
using std::set;
using std::string;
using std::map;
using std::pair;
using std::endl;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> s;
  for(const pair<int, string>& p: m){
    s.insert(p.second);
  }
  return s;
}

