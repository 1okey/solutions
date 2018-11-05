#include <iostream>

// - называется Factorial
// - возвращает int
// - принимает int и возвращает факториал своего аргумента.

// Гарантируется, что аргумент функции по модулю не превышает 10.
// Для отрицательных аргументов функция должна возвращать 1.

int Factorial(int n){
  if(n <= 1){
    return 1;
  } else {
    return n * Factorial(n - 1);
  }
}

int main() {
  int a;
  std::cin >> a;
  std::cout << Factorial(a);
  return 0;
}

