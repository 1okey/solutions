#pragma once

#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

void TestParseEvent();
void TestParseCondition();
void TestAddition();
void TestFind();
void TestAll();

template <class T>
ostream& operator << (ostream& os, const vector<T>& s);

template <class T>
ostream& operator << (ostream& os, const set<T>& s);

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) ;

void Assert(bool b, const string& hint);

class TestRunner{
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    ~TestRunner();
private:
    int fail_count = 0;
};

