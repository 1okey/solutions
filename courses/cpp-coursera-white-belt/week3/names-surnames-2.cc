#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

// Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
// Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного
// изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого
// человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName
// не обязаны возрастать.
//
// Гарантируется, что все имена и фамилии непусты.
//
// Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя
// и фамилию человека по состоянию на конец данного года.
//
// Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
//
// Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните
// "last_name with unknown first name".
//
// Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните
// "first_name with unknown last name".

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    if(first_names.count(year) == 0){
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if(last_names.count(year) == 0){
      last_names[year] = last_name;
    }
  }

  string GetLastValuableRecord(map<int,string>& collection, int year){
    string result = "";
    for(auto& pair: collection){
      if(pair.first <= year && !pair.second.empty()){
        result = pair.second;
      }
    }
    return result;
  }

  string GetAllNamesUntilYear(map<int,string>& collection, int year){
    vector<string> names;

    for(auto& pair: collection){
      if(pair.first <= year && !pair.second.empty()){
        names.push_back(pair.second);
      }
    }

    if (names.empty()) {
      return "";
    }
    reverse(begin(names), end(names));
    string result = names[0];

    for (int i = 1; i < names.size(); ++i) {
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

  string GetFullName(int year) {
    string first_name = GetLastValuableRecord(first_names, year);
    string last_name = GetLastValuableRecord(last_names, year);
    return CreateOutput(first_name, last_name);
  }

  string GetFullNameWithHistory(int year) {
    string first_name = GetAllNamesUntilYear(first_names, year);
    string last_name = GetAllNamesUntilYear(last_names, year);
    return CreateOutput(first_name, last_name);
  }

private:
  string CreateOutput(string& first_name, string& last_name){
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

  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

