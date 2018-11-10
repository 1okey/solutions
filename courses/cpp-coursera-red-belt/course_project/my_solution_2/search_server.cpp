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

bool Comparator(const pair<uint16_t, uint16_t>& lhs, const pair<uint16_t, uint16_t>& rhs) {
  return lhs.first  != rhs.first ? lhs.first  >  rhs.first : lhs.second <  rhs.second ;
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  index.Update(document_input);
}

void SearchServer::PutResultToOutput(
  ostream& search_results_output, vector<pair<uint16_t, uint16_t>>& result){
  for(size_t i = 0; i < (result.size() >= 5u ? 5u : result.size()); i++){
    if(result[i].first != 0){
      lock_guard<mutex> guard(server_mutex);
      search_results_output << " {" << "docid: " << result[i].second << ", "
                            << "hitcount: " << result[i].first << '}';
    }
  }
  {
    lock_guard<mutex> guard(server_mutex);
    search_results_output << '\n';
  }
}

void SearchServer::AddQueriesStreamThread(istream& query_input, ostream& search_results_output) {
  vector<pair<uint16_t, uint16_t>> result(index.GetDocsCount());

  for (string current_query; getline(query_input, current_query); ) {

    char sep = ' ';
    size_t b = 0;
    while ((b = current_query.find_first_not_of(sep, b)) != current_query.npos) {
        size_t e = current_query.find_first_of(sep, b);
        for (const auto& [docid, hitcount] : index.Lookup(current_query.substr(b, e-b))){
          auto& p = result[docid];
          p.first += hitcount;
          p.second = docid;
        }
        b = e;
    }

//    for(const auto& word : GetWords(current_query)){
//      for (const auto& [docid, hitcount] : index.Lookup(word)){
//        auto& p = result[docid];
//        p.first += hitcount;
//        p.second = docid;
//      }
//    }

    uint16_t head_size = result.size() > 5u ? 5u : result.size();
    partial_sort(result.begin(), next(result.begin(), head_size), result.end(), Comparator);
    {
      lock_guard<mutex> guard(server_mutex);
      search_results_output << current_query << ':';
    }
    PutResultToOutput(search_results_output, result);
    fill(result.begin(), result.end(), pair<uint16_t,uint16_t>(0,0));
  }
}

void SearchServer::AddQueriesStream(istream& query_input, ostream& search_results_output) {
    requests.push_back(async(launch::async, &SearchServer::AddQueriesStreamThread,
                             this, ref(query_input), ref(search_results_output)));
    if (requests.size() == 2){
        requests.clear();
    }
}

size_t InvertedIndex::GetDocsCount() {
  lock_guard<mutex> guard(index_mutex);
  return docs_count;
}

void InvertedIndex::Update(istream& document_input){
  Index new_index;
  uint16_t new_docs_count = 0;
  for (string current_document; getline(document_input, current_document); ) {
    char sep = ' ';
    size_t b = 0;
    while ((b = current_document.find_first_not_of(sep, b)) != current_document.npos) {
       size_t e = current_document.find_first_of(sep, b);
       new_index[current_document.substr(b, e-b)].first.push_back(new_docs_count);
       b = e;
    }
    new_docs_count++;
//    for (const auto& word : GetWords(current_document)) {
//      new_index[word].first.push_back(new_docs_count);
//    }
//    new_docs_count++;
  }
  for (auto& [key, value] : new_index) {
    for (const auto n : value.first) {
      value.second[n]++;
    }
  }

  lock_guard<mutex> guard(index_mutex);
  index = move(new_index);
  docs_count = new_docs_count;
}


const unordered_map<uint16_t,uint16_t>& InvertedIndex::Lookup(const string& word) {
  lock_guard<mutex> guard(index_mutex);
  if(auto it = index.find(word); it != index.end()){
    return index.at(word).second;
  }
  return empty_map;
}
