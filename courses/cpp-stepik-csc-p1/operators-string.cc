#include <cstddef> // size_t
#include "test_runner.h"
#include <algorithm>
#include <cstring>

// В этой задаче вам требуется реализовать оператор [] для уже известного вам класса String.
// Однако на этот раз оператор должен реализовывать нестандартное поведение: оператор нужно
// реализовать таким образом, чтобы для объекта str класса String можно было писать str[i][j]
// и это выражение возвращало подстроку начинающуюся в позиции i (считая с 0) и заканчивающуюся
// в позиции j (не включая).
//
// Например:
//
// String const hello("hello");
// String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
// String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
//
// Обратите внимание, что i может равняться j, в этом случае результатом должна быть пустая строка.
// Гарантируется, что i никогда не будет больше j, и они не будут выходить за пределы длины строки.
#include <cstddef> // size_t
#include <cstring>

struct String {
  String(const char *str = "");
  String(size_t n, char c);
  ~String();
  String(const String &other);
  String &operator=(const String &other);
  void append(const String &other);
  String& operator+=(const char s){
    str[size++] = s;
    return (*this);
  }

  struct Substring {
    Substring(const char * str, size_t from)
      : from(from), data(str) {}

    const String operator[](size_t end) const {
      String str("");
      for(size_t from_ = 0; from_ != end - from; from_++){
        str += data[from_];
      }
      return str;
    }

    size_t from;
    const char * data;
  };

  Substring operator[](size_t index) const {
    return Substring(str + index, index);
  }

  size_t size;
  char *str = nullptr;
};

int main(){
  const String hello("hello");
  const String hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
  const String empty = hello[0][0]; // теперь в hell хранится подстрока ""
  const String last = hello[4][5]; // теперь в hell хранится подстрока "o"
  const String empty_end = hello[5][5]; // теперь в hell хранится подстрока "o"
  const String ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
}

