#include <string>

using std::string;

struct Specialization {
  explicit Specialization(const string& specialization)
    : value(specialization)
  {}
  string value;
};

struct Course {
  explicit Course(const string& course)
    : value(course)
  {}
  string value;
};

struct Week {
  explicit Week(const string& week)
    : value(week)
  {}
  string value;
};

struct LectureTitle {
  LectureTitle(Specialization& s, Course& c, Week& w)
    : specialization(s.value), course(c.value), week(w.value)
  {}
  string specialization;
  string course;
  string week;
};

