#include <iostream>

// Дана строка. Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения.
// Если буква f в данной строке встречается только один раз, выведите число -1, а если
// не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.

int main() {
  std::string s;
  std::cin >> s;
  int occurence = 0;
  for(int index = 0; index < s.size(); index++){
    if(s[index] == 'f'){
      ++occurence;
    }
    if(occurence == 2){
      std::cout << index;
      return 0;
    }
  }
  std::cout << (occurence == 0 ? -2 : -1);
  return 0;
}

