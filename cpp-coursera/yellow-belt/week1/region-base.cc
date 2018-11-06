#include <iostream>
#include <cstdint>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using std::cin;
using std::string;
using std::map;
using std::cout;
using std::vector;
using std::max;

// Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и определяющую, 
// какое максимальное количество повторов она содержит. Две записи (объекты типа Region)
// считаются различными, если они отличаются хотя бы одним полем.

// Если все записи уникальны, считайте максимальное количество повторов равным 1. 
// Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для хранения ответа.

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs){
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
    tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
  int result = 0;
  map<Region, int> count;
  for(const Region& r: regions){
    result = max(result, ++count[r]);
  }
  return result;
}

