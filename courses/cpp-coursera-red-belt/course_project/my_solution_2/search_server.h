#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <future>

using namespace std;

using Index = unordered_map<string, pair<vector<uint16_t>, unordered_map<uint16_t, uint16_t>>>;

class InvertedIndex {
public:
  void Update(istream& document_input);
  const unordered_map<uint16_t,uint16_t>& Lookup(const string& words);
  size_t GetDocsCount();
private:
  mutex index_mutex;
  uint16_t docs_count = 0;
  Index index;
  unordered_map<uint16_t, uint16_t> empty_map;
};


class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStreamThread(istream& query_input, ostream& search_results_output);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);
  void PutResultToOutput(ostream& search_results_output,
                         vector<pair<uint16_t, uint16_t>>& result);
private:
  mutex server_mutex;
  InvertedIndex index;
  vector<future<void>> requests;
};
