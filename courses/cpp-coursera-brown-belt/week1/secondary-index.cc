#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::hash;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;

  bool operator==(const Record& other){
    return tie(id,title,user,timestamp,karma) ==
        tie(other.id, other.title, other.user, other.timestamp, other.karma);
  }
};



struct RecordHasher {
  size_t operator()(const Record& r){
    return ((shasher(r.id) + shasher(r.title) + shasher(r.user))
            / ihasher(r.timestamp) & ihasher(r.karma));
  }

  hash<string> shasher;
  hash<int> ihasher;
};

class Database {
public:
  Database(){}

  bool Put(const Record& record){
    return db.insert({record.id, record}).second;
  }

  const Record* GetById(const string& id) const {
    const auto it = db.find(id);
    return it == db.end() ? nullptr : &(it->second);
  }

  bool Erase(const string& id){
    auto it = db.find(id);
    if(it != db.end()){
      db.erase(it);
      return true;
    }
    return false;
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, const Callback& callback) const{
    bool in_progress = true;
    for(const auto& [key,record]: db){
      if(record.timestamp >= low && record.timestamp <= high && in_progress){
        in_progress = callback(record);
      }
    }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, const Callback& callback) const {
    bool in_progress = true;
    for(const auto& [key,record]: db){
      if(record.karma >= low && record.karma <= high && in_progress){
        in_progress = callback(record);
      }
    }
  }

  template <typename Callback>
  void AllByUser(const string& user, const Callback& callback) const {
    bool in_progress = true;
    for(const auto& [key,record]: db){
      if(record.user == user && in_progress){
        in_progress = callback(record);
      }
    }
  }
private:
  unordered_map<string, Record> db;
};


void TestRangeBoundaries() {
  const int good_karma = 1000;
  const int bad_karma = -10;

  Database db;
  db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
  db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

  int count = 0;
  db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestSameUser() {
  Database db;
  db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
  db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

  int count = 0;
  db.AllByUser("master", [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestReplacement() {
  const string final_body = "Feeling sad";

  Database db;
  db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
  db.Erase("id");
  db.Put({"id", final_body, "not-master", 1536107260, -10});

  auto record = db.GetById("id");
  ASSERT(record != nullptr);
  ASSERT_EQUAL(final_body, record->title);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRangeBoundaries);
  RUN_TEST(tr, TestSameUser);
  RUN_TEST(tr, TestReplacement);
  return 0;
}

