// https://www.hackerrank.com/challenges/vector-erase/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size, from, to, pos;
    cin >> size;
    vector<int> v(size);

    for(int & item : v) {
        cin >> item;
    }

    cin >> pos >> from >> to;
    --from;
    --to;
    v.erase(v.begin() + pos - 1);
    v.erase(v.begin() + from, v.begin() + to);

    cout << v.size() << '\n';
    for(int & item : v) {
        cout << item << ' ';
    }

    return 0;
}
