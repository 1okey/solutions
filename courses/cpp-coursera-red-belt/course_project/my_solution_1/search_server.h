#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class InvertedIndex {
public:
  void Update(istream& document_input);
  const unordered_map<size_t,size_t>& Lookup(const string& words) const;

  size_t GetDocsCount() const {
    return docs_count;
  }
  size_t docs_count = 0;
private:
  unordered_map<string, pair<vector<size_t>, unordered_map<size_t, size_t>>> index;
  unordered_map<size_t, size_t> empty_map;
};

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
  InvertedIndex index;
};
