#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

//В этом задании вам предстоит написать две небольшие программы. Каждый пункт - отдельная задача,
//решение отправляйте в поле с соответствующим номером.
//
//Часть 1
//Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
//Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

int main(){
  ifstream file("input.txt");
  ofstream output_file("output.txt");
  if(file.is_open()){
    string line;
    while(getline(file,line)){
      //1. cout << line << endl;
      //2. output_file << line << endl;
    }
  }
  return 0;
}

