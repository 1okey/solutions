#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>


class Date {
public:
  Date(const int& new_year, const int& new_month, const int& new_day);
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
  std::string ToString() const;
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);
Date ParseDate(std::istream& date);
std::string ParseEvent(std::istream& is);
