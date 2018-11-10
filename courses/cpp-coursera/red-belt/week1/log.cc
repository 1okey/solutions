#include <iostream>
#include <string>
#include <sstream>

#include "test_runner.h"

using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }
  void SetFile(const string& file) { file_name = file; }
  void SetLine(const int& line) { line_ = line; }

  void Log(const string& message){
    if(log_file){
      os << file_name << (log_line ? "" : " ");
    }
    if(log_line){
      os << (log_file ? ":" : "Line ") << line_ << " ";
    }
    os << message << '\n';
  }

private:
  string file_name;
  int line_;
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) \
  logger.SetLine(__LINE__);   \
  logger.SetFile(__FILE__);   \
  logger.Log(message)

void TestLog() {
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}

