#include <string>
#include <vector>
#include <algorithm>

// Реализуйте класс, поддерживающий набор строк в отсортированном порядке.
// Класс должен содержать два публичных метода:

using std::vector;
using std::string;

class SortedStrings {
public:
  void AddString(const string& s) {
    collection.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(collection.begin(),collection.end());
    return vector<string>{collection.begin(), collection.end()};
  }
private:
  vector<string> collection;
};

