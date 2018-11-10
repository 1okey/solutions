#pragma once

#include "date.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <functional>
#include <utility>

using Predicate =  std::function<bool(const Date &, const std::string&)>;

class Database {
public:
  void Add(const Date& date, const std::string& event);
  int DeleteDate(const Date& date);
  std::vector<std::pair<Date, std::string>> FindIf(const Predicate& predicate) const;
  int RemoveIf(const Predicate& predicate);
  std::pair<Date, std::string> Last(const Date & date) const;
  void Print(std::ostream& out) const;
private:
  std::map<Date, std::set<std::string>> storage;
  std::map<Date, std::vector<std::string>> ordered;
};

std::ostream& operator<<(std::ostream& out,const std::pair<Date, std::vector<std::string>>& p);
std::ostream& operator<<(std::ostream& out,const std::pair<Date, std::string>& p);
std::string ParseEvent(std::istream& is);
