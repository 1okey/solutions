// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> v(n);
    for(int & i : v) {
        cin >> i;
    }
    cin >> n;
    sort(v.begin(), v.end());

    while(n != 0) {
        cin >> q;
        auto it = lower_bound(v.begin(), v.end(), q);
        cout << (*it == q ? "Yes " : "No ") << (distance(v.begin(),it) + 1)<< endl; 
        --n;
    }

    return 0;
}
