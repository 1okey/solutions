#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

// Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим
// задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен
// иметь конструктора по умолчанию.
//
// При получении на вход года, который меньше года рождения:
//
// методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
// методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
// Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

class Person {
public:
  Person(const string& first_name, const string& last_name, int year){
    first_names[year] = first_name;
    last_names[year] = last_name;
    date_of_birth = year;
  }

  void ChangeFirstName(int year, const string& first_name) {
    if(year >= date_of_birth && first_names.count(year) == 0){
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if(year >= date_of_birth && last_names.count(year) == 0){
      last_names[year] = last_name;
    }
  }

  string GetLastValuableRecord(const map<int,string>& collection, int year) const {
    string result = "";


    for(auto& pair: collection){
      if(pair.first <= year && !pair.second.empty()){
        result = pair.second;
      }
    }
    return result;
  }

  string GetAllNamesUntilYear(const map<int,string>& collection, int year) const {
    vector<string> names;


    for (const auto& item : collection) {
      if (item.first <= year && (names.empty() || names.back() != item.second)) {
        names.push_back(item.second);
      }
    }

    if (names.empty()) {
      return "";
    }

    reverse(begin(names), end(names));
    string result = names[0];

    for (size_t i = 1; i < names.size(); ++i) {
      if (i == 1) {
        result += " (";
      } else {
        result += ", ";
      }
      result += names[i];
    }
    if (names.size() > 1) {
      result += ")";
    }
    return result;
  }

  string GetFullName(int year) const {
    if(year < date_of_birth){
      return "No person";
    }
    string first_name = GetLastValuableRecord(first_names, year);
    string last_name = GetLastValuableRecord(last_names, year);
    return CreateOutput(first_name, last_name);
  }

  string GetFullNameWithHistory(int year) const {
    if(year < date_of_birth){
      return "No person";
    }
    string first_name = GetAllNamesUntilYear(first_names, year);
    string last_name = GetAllNamesUntilYear(last_names, year);
    return CreateOutput(first_name, last_name);
  }

private:
  string CreateOutput(string& first_name, string& last_name) const {
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if(first_name.empty()){
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    } else {
      return  first_name + " " + last_name;
    }
  }

  int date_of_birth;
  map<int, string> first_names;
  map<int, string> last_names;
};

