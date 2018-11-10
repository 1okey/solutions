#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
    return lhs.age < rhs.age;
  }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons){
  auto females = partition(persons.begin(), persons.end(),[](const Person& p){
    return p.gender == Gender::FEMALE;
  });

  auto empl_femailes = partition(persons.begin(), females,[](const Person& p){
    return p.is_employed;
  });

  auto empl_males = partition(females, persons.end(),[](const Person& p){
    return p.is_employed;
  });

  cout << "Median age = "
       << ComputeMedianAge(begin(persons), end(persons)) << endl;
  cout << "Median age for females = "
       << ComputeMedianAge(begin(persons), females) << endl;
  cout << "Median age for males = "
       << ComputeMedianAge(females, end(persons)) << endl;
  cout << "Median age for employed females = "
       << ComputeMedianAge(begin(persons),  empl_femailes) << endl;
  cout << "Median age for unemployed females = "
       << ComputeMedianAge(empl_femailes, females) << endl;
  cout << "Median age for employed males = "
       << ComputeMedianAge(females, empl_males) << endl;
  cout << "Median age for unemployed males = "
       << ComputeMedianAge(empl_males, end(persons)) << endl;
}

