#include <map>
#include <iostream>
#include <string>

using std::map;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::exception;

// Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и значение ключа k.
// Если элемент по ключу k в коллекции отсутствует, то функция должна бросить исключение
// runtime_error, иначе вернуть ссылку на элемент в коллекции.

template<typename K, typename V>
V& GetRefStrict(map<K,V>& m, const K& key){
  try {
    return m.at(key);
  } catch (exception& e) {
    throw runtime_error(e.what());
  }
}


