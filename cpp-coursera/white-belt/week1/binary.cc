#include <iostream>
#include <string>

// На вход дано целое положительное число N. Выведите его в двоичной системе
// счисления без ведущих нулей.

using std::cin;
using std::string;
using std::cout;
using std::to_string;

int main(){
  int a;
  cin >> a;
  string binary;
  while(a > 0){
    binary += to_string(a % 2);
    a >>= 1;
  }
  cout << binary;
  return 0;
}

