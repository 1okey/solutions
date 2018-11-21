#include <cstddef> // size_t
#include "test_runner.h"
#include <algorithm>

unsigned strlen(const char *str);
void strcat(char *to, const char *from);
int strstr(const char *text, const char *pattern);
void strcpy(char* target, const char* source);
void strfill(char * source, char s, unsigned number);

unsigned strlen(const char *str)
{
  unsigned c = 0;
  while(*(str++) != 0) c++;
  return c;
}

void strcat(char *to, const char *from){
  int l1 = strlen(to);
  while(*from != '\0'){
    to[l1++] = *from;
    from++;
  }
  to[l1++] = '\0';
}

int strstr(const char *text, const char *pattern)
{
  if(*pattern == 0){
    return 0;
  }

  for(unsigned i = 0; *text != 0; i++){
    if(*text == *pattern){
      const char* pattern_it = pattern;
      const char* source_it = text;
      while(*pattern_it != 0){
        if(*pattern_it != *source_it){
          break;
        }
        pattern_it++; source_it++;
      }

      if(*pattern_it == 0){
        return i;
      }
    }
    text++;
  }
  return -1;
}

void strcpy(char* target, const char* source){
  while((*(target++) = *(source++)) != 0);
}

void strfill(char * source, char s, size_t number){
  size_t ind = 0;
  for(;ind < number; source[ind] = s, ind++);
  source[++ind] = 0;
}


struct String {
  String(const char *source = "")
    : size(strlen(source)), str(new char[strlen(source)] + 1)
  {
    strcpy(str, source);
  }

  String(size_t n, char c)
    : size(n), str(new char[n + 1])
  {
    strfill(str, c, n);
  }

  String(const String& other)
  {
    new (this) String(other.str);
  }

  ~String(){
    delete []str;
  }

  String& operator=(const String& other){
    String(other.str).swap(*this);
    return *this;
  }

  void swap(String& other){
    std::swap(size, other.size);
    std::swap(str, other.str);
  }

  void append(String &other)
  {
    size += other.size;
    char * new_str = new char [size];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    delete [] str;
    str = new_str;
  }

  size_t size;
  char *str = nullptr;
};

// TESTS ================================================================================== TESTS //

bool compareStrings(char * result, char * source){
  while(*result != 0){
    if(*(result++) != *(source++)){
      return false;
    }
  }
  return true;
}

void CheckDefault(){
  char source[1] = {0};
  String s_obj(source);
  ASSERT_EQUAL(s_obj.size, 0);
  ASSERT(compareStrings(s_obj.str, source));
}

void CheckCopy(){
  char source[11] = {'s','o','m','e','s','t','r','i','n','g', 0};
  String s_obj(source);
  ASSERT_EQUAL(s_obj.size, 10);
  ASSERT(compareStrings(s_obj.str, source));
}

void CheckFill(){
  String s_obj(4, 'c');
  ASSERT_EQUAL(s_obj.size, 4);
  char result[5] = {'c','c','c','c', 0};
  ASSERT(compareStrings(s_obj.str, result));
}

void CheckAppend(){
  String s_obj(4, 'c');
  ASSERT_EQUAL(s_obj.size, 4);
  String s_obj2(2, 'o');
  s_obj.append(s_obj2);
  char result[7] = {'c','c','c','c','o', 'o', 0};
  ASSERT(compareStrings(s_obj.str, result));
}

int main(){
  TestRunner runner;
  RUN_TEST(runner,CheckDefault);
  RUN_TEST(runner,CheckCopy);
  RUN_TEST(runner,CheckFill);
  RUN_TEST(runner,CheckAppend);

}
