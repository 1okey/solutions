#include <date.h>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs) {
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
    vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

bool operator>(const Date& lhs, const Date& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return (lhs == rhs) || (lhs > rhs);
}
bool operator<=(const Date& lhs, const Date& rhs) {
    return (lhs == rhs) || (lhs < rhs);
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
      "-" << setw(2) << setfill('0') << date.GetMonth() <<
      "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

Date::Date(const int& new_year, const int& new_month, const int& new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}

string Date::ToString() const {
    string date = to_string(day) + "." + to_string(month) + "." + to_string(year);
    return date;
}

Date ParseDate(istream& date_stream) {
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);

  if (!ok) {
    throw logic_error("Wrong date format");
  }

  return Date(year, month, day);
}
