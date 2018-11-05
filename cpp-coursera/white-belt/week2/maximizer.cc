#include <iostream>

// Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента:
// first и second. Если first оказался больше second, Ваша функция должна записывать
//в second значение параметра first. При этом изменение параметра second должно быть видно
// на вызывающей стороне.

void UpdateIfGreater(int& a, int& b){
  if(a > b){
    int tmp = a;
    a = b;
    b = tmp;
  }
}
