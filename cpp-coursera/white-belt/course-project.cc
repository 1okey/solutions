#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

struct Date {
    Date(){}
    Date(int year, int month, int day): year_(year), month_(month), day_(day){}
    int GetYear() const {
        return year_;
    }
    int GetMonth() const{
        return month_;
    }
    int GetDay() const{
        return day_;
    }
private:
    int year_ = 0;
    int month_ = 0;
    int day_ = 0;
};

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    } else if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() < rhs.GetMonth())) {
        return true;
    } else if ((lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() < rhs.GetDay())) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& stream, const Date& rhs){
    stream << fixed << setfill('0');
    stream << setw(4) << rhs.GetYear() << '-' << setw(2) << rhs.GetMonth() << '-' << setw(2) << rhs.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        if(db.count(date) <= 0){
            db[date].push_back(event);
            SortEvents(date);
        } else {
            vector<string> & events = db.at(date);
            if(!EventExists(events, event)){
                events.push_back(event);
                SortEvents(date);
            }
        }
    }
    bool DeleteEvent(const Date& date, const string& event){
        if(db.count(date) > 0){
            vector<string> & events = db.at(date);
            if(EventExists(events, event)){
                events.erase(find(events.begin(), events.end(), event));
                return true;
            }
        }
        return false;
    }
    size_t DeleteDate(const Date& date){
        size_t size = 0;
        if(db.count(date) > 0){
            size = db.at(date).size();
            db.erase(date);
        }
        return size;
    }
    void Find(const Date& date) const {
        if(db.count(date) > 0){
            for(auto & event : db.at(date)){
                cout << event << endl;
            }
        }
    }
    void Print() const {
        for(auto & item: db){
            for(auto & event :db.at(item.first))
                cout << item.first << " " << event << endl;
        }
    }
private:
    bool EventExists(const vector<string> & events, const string & event){
        return find(events.begin(), events.end(), event) != events.end();
    }
    void SortEvents(const Date & date){
        vector<string> & events = db.at(date);
        sort(events.begin(), events.end());
    }

    map<Date, vector<string>> db;
};

Date ParseDate(const string & datestring){
    int year, month, day;
    stringstream dateStream;
    dateStream.str(datestring);

    dateStream >> year;
    if (dateStream.peek() == '-') {
        dateStream.ignore(1);
    } else {
        string ex = "Wrong date format: " + datestring;
        throw runtime_error(ex);
    }

    dateStream >> month;
    if (dateStream.peek() == '-') {
        dateStream.ignore(1);
    } else {
        string ex = "Wrong date format: " + datestring;
        throw runtime_error(ex);
    }
    dateStream >> day;
    if (dateStream.peek() != EOF) {
        string ex = "Wrong date format: " + datestring;
        throw runtime_error(ex);
    }
    if (month < 1 || month > 12) {
        string ex = "Month value is invalid: " + to_string(month);
        throw runtime_error(ex);
    }
    if (day < 1 || day > 31) {
        string ex = "Day value is invalid: " + to_string(day);
        throw runtime_error(ex);
    }
    return {year, month, day};
}

vector<string> GetParams(const string & line){
    vector<string> params;
    size_t i = 0, j = 0;
    string word;
    for(auto & ch : line){
        j++;
        if((ch == ' ' || line.length() == j) && i < 2){
            if(j == line.length()){
                word.push_back(ch);
            }
            params.push_back(word);
            word = "";
            i++;
        } else {
            word.push_back(ch);
        }
        if(i == 2 && j == line.length()){
            params.push_back(word);
        }
    }
    if(params.size() < 3){
        params.resize(3,"");
    }

    return params;
}

int main(){
    Database db;
    string line;
    vector<string> params;
    while(getline(cin, line)){
        if(line.empty())
            continue;

        params = GetParams(line);
        string command = params[0];
        Date date;
        string & event = params[2];
        if(command == "Add") {
            try {
                date = ParseDate(params[1]);
                db.AddEvent(date, event);
            } catch( exception& ex) {
                cout << ex.what() << endl;
            }
        } else if (command == "Del"){
            try {
                date = ParseDate(params[1]);
                if(event == ""){
                    size_t eventsSize = db.DeleteDate(date);
                    cout << "Deleted " << eventsSize << " events" << endl;
                } else {
                    bool found = db.DeleteEvent(date,event);
                    cout << (found ? "Deleted successfully" : "Event not found") << endl;
                }
            } catch( exception& ex) {
                cout << ex.what() << endl;
            }
        } else if (command == "Find"){
            try {
                date = ParseDate(params[1]);
                db.Find(date);
            } catch( exception& ex) {
                cout << ex.what() << endl;
            }
        } else if (command == "Print"){
            db.Print();
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }
    return 0;
}
