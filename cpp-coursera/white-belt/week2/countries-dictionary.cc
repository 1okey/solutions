#include <iostream>
#include <string>
#include <map>

// Реализуйте справочник столиц стран.

// На вход программе поступают следующие запросы:

// -- CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital,
// либо добавление такой страны с такой столицей, если раньше её не было.
// -- RENAME old_country_name new_country_name — переименование страны из old_country_name в
// new_country_name.
// -- ABOUT country — вывод столицы страны country.
// -- DUMP — вывод столиц всех стран.

// ФОРМАТ ВВОДА
// В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов.
// Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.
//
// ФОРМАТ ВЫВОДА
// Выведите результат обработки каждого запроса:
//
// В ответ на запрос CHANGE_CAPITAL country new_capital выведите:
// -- Introduce new country country with capital new_capital, если страны country раньше
// не существовало;
// -- Country country hasn't changed its capital, если страна country до текущего момента имела
// столицу new_capital;
// -- Country country has changed its capital from old_capital to new_capital, если страна country
// до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.

// В ответ на запрос RENAME old_country_name new_country_name выведите
// Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name
// не существует или страна new_country_name уже существует;
// Country old_country_name with capital capital has been renamed to new_country_name, если запрос
// корректен и страна имеет столицу capital.

// В ответ на запрос ABOUT country выведите
// Country country doesn't exist, если страны с названием country не существует;
// Country country has capital capital, если страна country существует и имеет столицу capital.

// В ответ на запрос DUMP выведите
// There are no countries in the world, если пока не было добавлено ни одной страны;
// разделённые пробелами пары country/capital, описывающие столицы всех стран и упорядоченные
// по названию страны, если в мире уже есть хотя бы одна страна.


using std::cin;
using std::cout;
using std::string;
using std::map;
using std::endl;

void ChangeCapital(map<string,string>& dict, string& country, string& new_capital);
void RenameCountry(map<string,string>& dict, string& old_name, string& new_name);
void PrintCountry(map<string,string>& dict, string& country);
void DumpDictionary(map<string,string>& dict);

int main() {
  int q;
  cin >> q;

  map<string, string> country_to_capital;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;
    if (operation_code == "CHANGE_CAPITAL") {
      string country, new_capital;
      cin >> country >> new_capital;
      ChangeCapital(country_to_capital, country, new_capital);
    } else if (operation_code == "RENAME") {
      string old_country_name, new_country_name;
      cin >> old_country_name >> new_country_name;
      RenameCountry(country_to_capital, old_country_name, new_country_name);
    } else if (operation_code == "ABOUT") {
      string country;
      cin >> country;
      PrintCountry(country_to_capital, country);
    } else if (operation_code == "DUMP") {
      DumpDictionary(country_to_capital);
    }
  }

  return 0;
}

void ChangeCapital(map<string,string>& dict, string& country, string& new_capital){
  if (dict.count(country) == 0) {
    cout << "Introduce new country " << country << " with capital " << new_capital << endl;
  } else {
    const string& old_capital = dict[country];
    if (old_capital == new_capital) {
      cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
      cout << "Country " << country << " has changed its capital from "
           << old_capital << " to " << new_capital << endl;
    }
  }
  dict[country] = new_capital;
}

void RenameCountry(map<string,string>& dict, string& old_name, string& new_name){
  if (old_name == new_name || dict.count(old_name) == 0 || dict.count(new_name) == 1) {
    cout << "Incorrect rename, skip" << endl;
  } else {
    cout << "Country " << old_name << " with capital " << dict[old_name]
            << " has been renamed to " << new_name << endl;
    dict[new_name] = dict[old_name];
    dict.erase(old_name);
  }
}

void PrintCountry(map<string,string>& dict, string& country){
  if (dict.count(country) == 0) {
    cout << "Country " << country << " doesn't exist" << endl;
  } else {
    cout << "Country " << country << " has capital " << dict[country] << endl;
  }
}

void DumpDictionary(map<string,string>& dict){
  if (dict.empty()) {
    cout << "There are no countries in the world" << endl;
  } else {
    for (const auto& country_item : dict) {
      cout << country_item.first << "/" << country_item.second << " ";
    }
    cout << endl;
  }
}


