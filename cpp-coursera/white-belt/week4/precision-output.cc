#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//В этом задании вам предстоит написать две небольшие программы. Каждый пункт - отдельная задача,
//решение отправляйте в поле с соответствующим номером.
//
//Часть 1
//Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
//Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

int main(){
  ifstream file("input.txt");
  if(file.is_open()){
    double num;
    cout << fixed << setprecision(3);
    while(file >> num){
      cout << num << endl;
    }
  }
  return 0;
}

