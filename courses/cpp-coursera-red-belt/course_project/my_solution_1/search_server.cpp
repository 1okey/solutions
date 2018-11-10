#include "search_server.h"
#include "iterator_range.h"
//#include "profile.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <set>

vector<string> GetWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  index.Update(document_input);
}

void SearchServer::AddQueriesStream(istream& query_input, ostream& search_results_output) {

  vector<pair<size_t, size_t>> result(index.GetDocsCount());
  for (string current_query; getline(query_input, current_query); ) {
    for(const auto& w : GetWords(current_query)){
      for (const auto& [docid, hitcount] : index.Lookup(w)){
        auto& p = result[docid];
        p.first += hitcount;
        p.second = docid;
      }
    }
    size_t head_size = result.size() > 5u ? 5u : result.size();

    partial_sort(result.begin(), result.begin() + head_size, result.end(),
                 [](const pair<size_t, size_t>& lhs, const pair<size_t, size_t>& rhs) {
      return lhs.first  != rhs.first ? lhs.first  >  rhs.first : lhs.second <  rhs.second ;
    });

    search_results_output << current_query << ':';
    for(size_t i = 0;
        i < (result.size() >= 5u ? 5u : result.size());
        i++){
      if(result[i].first != 0){
        search_results_output << " {"
                              << "docid: " << result[i].second << ", "
                              << "hitcount: " << result[i].first << '}';
      }
    }

    search_results_output << '\n';
    fill(result.begin(), result.end(), pair<size_t,size_t>(0,0));
  }
}

void InvertedIndex::Update(istream& document_input){
  docs_count = 0;
  index.clear();
  for (string current_document; getline(document_input, current_document); ) {
    for (const auto& word : GetWords(current_document)) {
      index[word].first.push_back(docs_count);
    }
    docs_count++;
  }
  for (auto& [key, value] : index) {
    for (const auto n : value.first) {
      value.second[n]++;
    }
  }}


const unordered_map<size_t,size_t>& InvertedIndex::Lookup(const string& word) const {
  if(auto it = index.find(word); it != index.end()){
    return index.at(word).second;
  }
  return empty_map;
}
