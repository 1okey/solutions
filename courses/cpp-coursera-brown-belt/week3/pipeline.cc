#include "test_runner.h"
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <functional>

using namespace std;

struct Email {
  Email(){}
  Email(const string& from, const string& to, const string& body)
    :from(from), to(to), body(body)
  {}
  string from = "";
  string to  = "";
  string body = "";
};

class Worker {
public:
  virtual ~Worker() = default;
  virtual void Process(unique_ptr<Email> email) = 0;
  virtual void Run() {
    throw logic_error("Unimplemented");
  }
  void SetNext(unique_ptr<Worker> next) {
    next_ = move(next);
  }
protected:
  unique_ptr<Worker> next_ = nullptr;
  void PassOn(unique_ptr<Email> email) const {
    if(next_ != nullptr){
      next_->Process(move(email));
    }
  }
};

class Reader : public Worker {
public:
  Reader(istream& is) : is(is) {}
  void Run() override {
    vector<string> parts;
    for(string line; getline(is, line);){
      parts.push_back(line);
      if(parts.size() == 3){
        unique_ptr<Email> email = make_unique<Email>(parts[0],parts[1],parts[2]);
        PassOn(move(email));
        parts.clear();
      }
    }
  }
  void Process(unique_ptr<Email> email) override {}
private:
  istream& is;
};


class Filter : public Worker {
public:
  using Function = function<bool(const Email&)>;
  Filter(const Function& predicate)
    : predicate_(predicate)
  {}
  void Process(unique_ptr<Email> email) override {
    if(predicate_(*email.get())){
      PassOn(move(email));
    }
  }
private:
  Function predicate_;
};


class Copier : public Worker {
public:
  Copier(const string& address)
    :address_(move(address))
  {}
  void Process(unique_ptr<Email> email) override {
    string original_recepient = email->to;
    unique_ptr<Email> email_copy = make_unique<Email>(email->from, address_, email->body);
    this->PassOn(move(email));
    if(original_recepient != address_){
      this->PassOn(move(email_copy));
    }
  }
private:
  string address_;
};


class Sender : public Worker {
public:
  Sender(ostream& os)
    : os_(os)
  {}
  void Process(unique_ptr<Email> email) override {
    os_ << email->from << '\n'
        << email->to << '\n'
        << email->body << '\n';
    PassOn(move(email));
  }
private:
  ostream& os_;
};


class PipelineBuilder {
public:
  explicit PipelineBuilder(istream& in)
    : reader_(make_unique<Reader>(in))
  {}

  PipelineBuilder& FilterBy(Filter::Function filter){
    pipe.push_back(make_unique<Filter>(filter));
    return *this;
  }

  PipelineBuilder& CopyTo(const string& recipient){
    pipe.push_back(make_unique<Copier>(recipient));
    return *this;
  }

  PipelineBuilder& Send(ostream& out){
    pipe.push_back(make_unique<Sender>(out));
    return *this;
  }

  unique_ptr<Worker> Build(){
    pipe.insert(pipe.begin(), move(reader_));
    auto worker = pipe.rbegin();
    for(;worker != pipe.rend() && next(worker) != pipe.rend(); worker++){
      (*next(worker))->SetNext(move(*worker));
    }
    return move(pipe.front());
  }
private:
  vector<unique_ptr<Worker>> pipe;
  unique_ptr<Worker> reader_;
};

void TestRead(){
  string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n"
        );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  auto pipeline = builder.Build();

  pipeline->Run();

  string expectedOutput = ("");

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

void TestSend(){
  string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n"
        );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  auto pipeline = builder.Send(outStream).Build();

  pipeline->Run();

  string expectedOutput = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n");

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

void TestSanity() {
  string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n"
        );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  auto pipeline = builder
      .FilterBy([](const Email& email) { return email.from == "erich@example.com"; })
      .CopyTo("richard@example.com")
      .Send(outStream)
      .Build();

  pipeline->Run();

  string expectedOutput = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "erich@example.com\n"
        "richard@example.com\n"
        "Are you sure you pressed the right button?\n"
        );

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

void TestFilter(){
  string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "anton@example.com\n"
        "I do not make mistakes of that kind\n"
        );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  auto pipeline = builder
      .FilterBy([](const Email& email) { return email.to== "richard@example.com"; })
      .Send(outStream)
      .Build();

  pipeline->Run();

  string expectedOutput = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"
        );

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

void TestEmptyOutput(){
  string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "george@example.com\n"
        "I do not make mistakes of that kind\n"
        );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  auto pipeline = builder
      .FilterBy([](const Email& email) { return email.to== "anton@example.com"; })
      .Send(outStream)
      .Build();

  pipeline->Run();

  string expectedOutput = ("");
  ASSERT_EQUAL(expectedOutput, outStream.str());
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRead);
  RUN_TEST(tr, TestSend);
  RUN_TEST(tr, TestSanity);
  RUN_TEST(tr, TestFilter);
  RUN_TEST(tr, TestEmptyOutput);

  return 0;
}

