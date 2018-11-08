#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {
  auto result_of_insert = storage[date].insert(event);
  if (result_of_insert.second) {
    ordered[date].push_back(event);
  }
}

void Database::Print(ostream& out) const {
  for (const auto& item : ordered) {
    for (const string& event : item.second) {
      out << item.first << " " << event << endl;
    }
  }
}

pair<Date, string> Database::Last(const Date& date) const {
  if(ordered.empty() || date < ordered.begin()->first){
    throw invalid_argument("No event available before: " + date.ToString());
  }

  const auto begin = ordered.begin();
  if(date == begin->first){
    return make_pair(begin->first, begin->second.back());
  }

  const auto end = ordered.rbegin();
  if(date >= end->first){
    return make_pair(end->first, end->second.back());
  }

  auto lower_b = ordered.lower_bound(date);
  if (lower_b->first == date) {
    return make_pair(lower_b->first, lower_b->second.back());
  }
  else {
    return make_pair(prev(lower_b)->first, prev(lower_b)->second.back());
  }
}

vector<pair<Date, string>> Database::FindIf(const Predicate& predicate) const {
  vector<pair<Date, string>> result;
  for(const auto & p : ordered){
    for(const auto & e : p.second){
      if(predicate(p.first, e)){
        result.push_back(make_pair(p.first, e));
      }
    }
  }
  return result;
}

int Database::RemoveIf(const Predicate& predicate) {
  int deleted_events = 0;
  auto order_it = ordered.begin();
  for (auto stor_it = storage.begin(); stor_it != storage.end();) {
    set<string>& set_events = stor_it->second;
    vector<string>& events = order_it->second;

    for (auto it = set_events.begin(); it != set_events.end();) {
      if (predicate(stor_it->first, *it)) {
        events.erase(remove(events.begin(),events.end(), *it), events.end());
        it = set_events.erase(it);
        deleted_events++;
      } else {
        ++it;
      }
    }

    if (storage.at(stor_it->first).empty()) {
      order_it = ordered.erase(order_it);
      stor_it = storage.erase(stor_it);
    }

    else {
      ++stor_it;
      ++order_it;
    }

  }

  return deleted_events;
}

ostream& operator<<(std::ostream& out,const std::pair<Date, std::vector<std::string>>& p){
  out << p.first << " ";
  for(const auto& i: p.second){
    out << i << " ";
  }
  return out;
}
ostream& operator<<(std::ostream& out,const std::pair<Date, std::string> & p){
  out << p.first << " ";
  for(const auto& i: p.second){
    out << i;
  }
  return out;
}

string ParseEvent(istream& is) {
  string event;

  bool leading_space = is.peek() == ' ';
  while (leading_space) {
    is.ignore(1);
    leading_space = is.peek() == ' ';
  }

  getline(is, event);
  return event;
}
