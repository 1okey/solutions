#include "test_runner.h"

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try {
        func();
        cerr << test_name << " OK" << endl;
    } catch (exception& e) {
        ++fail_count;
        cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
        ++fail_count;
        cerr << "Unknown exception caught" << endl;
    }
}

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}


using namespace std;

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("  first event  \n  second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestAddition(){
    map<Date, vector<string>> dates {
        { Date(2017,2,2),{"first event", "second event"} },
        { Date(2017,3,3), {"third event"} },
    };
    Database db;
    for(const auto & i : dates){
        for(const auto & e : i.second){
            db.Add(i.first, e);
        }
    }
    db.Print(cout);
}

void TestRemove(){
    {
        cout << '\n' << "Remove #1" << endl;
        map<Date, vector<string>> dates {
            { Date(2017,10,1),{"first event", "second event"} },
            { Date(2017,5,1), {"second event", "first event"} },
            { Date(2017,4,1), {"first event", "third event", "third event", "second event"} },
            { Date(2017,3,1), {"third event", "first event", "second event", "second event"} },
        };
        Database db;
        for(const auto & i : dates){
            for(const auto & e : i.second){
                db.Add(i.first, e);
            }
        }
        istringstream ss(R"(date >= 2017-03-01 AND event == "second event")");
        cout << "Remove" << endl;
        auto condition = ParseCondition(ss);
        auto predicate = [condition](const Date& date, const string& event) {
            return condition->Evaluate(date, event);
        };
        int result = db.RemoveIf(predicate);
        cout << "Removed " << to_string(result) << " entries" << endl;
        db.Print(cout);
        try {
            cout << "Last" << endl;
            const auto p = db.Last(Date(2017,3,1));
            cout << p << endl;
        } catch (exception & e) {
            cout << "No entries" << endl;
        }
    }
    {
        cout << '\n' << "Remove #2" << endl;
        vector<pair<Date, vector<string>>> dates = {
            { Date(2017,10,1),{"first event", "second event"} },
            { Date(2017,5,1), {"second event", "first event"} },
            { Date(2017,4,1), {"first event", "third event", "third event", "second event"} },
            { Date(2017,3,1), {"third event", "first event", "second event", "second event"} },
        };
        Database db;
        for(const auto & i : dates){
            for(const auto & e : i.second){
                db.Add(i.first, e);
            }
        }
        istringstream ss(R"()");
        db.Print(cout);
        cout << "Remove" << endl;
        auto condition = ParseCondition(ss);
        auto predicate = [condition](const Date& date, const string& event) {
            return condition->Evaluate(date, event);
        };
        int result = db.RemoveIf(predicate);
        cout << "Removed " << to_string(result) << " entries" << endl;
        dates = {
            { Date(2017,5,1), {"first event", "second event"} },
            { Date(2017,5,1), {"second event", "first event"} },
            { Date(2017,5,1), {"first event", "third event", "third event", "second event"} },
            { Date(2017,5,1), {"third event", "first event", "second event", "second event"} },
        };
        ;
        for(const auto & i : dates){
            for(const auto & e : i.second){
                db.Add(i.first, e);
            }
        }
        db.Print(cout);
    }
}
void TestFind(){
    map<Date, vector<string>> dates {
        { Date(2017,2,2), {"first event", "second event"} },
        { Date(2017,3,3), {"third event"} },
    };

    Database db;
    for(const auto & i : dates){
        for(const auto & e : i.second){
            db.Add(i.first, e);
        }
    }

    istringstream ss(R"(date > 2017-10-01)");
    auto condition = ParseCondition(ss);
    auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
    };
    const auto result = db.FindIf(predicate);
    for(const auto & p : result)
    {
        cout << p << endl;
    }
    cout << "Found " << result.size() << " entries" << endl;
}


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
    tr.RunTest(TestAddition, "TestAddition");
    tr.RunTest(TestFind, "TestFind");
    tr.RunTest(TestRemove, "TestRemove");
}
