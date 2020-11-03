// https://www.hackerrank.com/challenges/arrays-ds/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the reverseArray function below.
vector<int> reverseArray(vector<int> a) {
    vector<int> reversed = vector<int>(a.size(), 0);

    for (size_t i = 0; i < a.size(); ++i)
    {
        reversed[a.size() - i - 1] = a[i];
    }

    return reversed;
}