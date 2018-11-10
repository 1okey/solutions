#include <string>
#include <algorithm>
#include <iostream>

// Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы
// Reverse для переворота строки и ToString для получения строки.

using std::string;
using std::cout;
using std::cin;
using std::endl;

class ReversibleString {
public:
  ReversibleString() = default;
  ReversibleString(const string& s): s(s){}

  void Reverse(){
    reverse(s.begin(), s.end());
  }

  string ToString() const {
    return s;
  }
private:
  string s = "";
};

