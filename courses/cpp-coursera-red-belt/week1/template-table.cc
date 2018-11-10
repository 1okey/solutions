#include "test_runner.h"

using namespace std;

template <typename T>
class Table {
public:
  Table(const size_t& y, const size_t& x)
    : collection(vector<vector<T>>(y, vector<T>(x)))
  {}


  vector<T>& operator[](const size_t& index) {
    return collection[index];
  }

  const vector<T>& operator[](const size_t& index) const {
    return collection[index];
  }

  void Resize(const size_t& y, const size_t& x){
    collection.resize(y);
    for(vector<T>& row: collection){
      row.resize(x);
    }
  }

  pair<size_t, size_t> Size() const {
    return {collection.size(), collection[0].size()};
  }
private:
  vector<vector<T>> collection;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}

