// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q, q1, q2 ,size;
    cin >> n >> q;
    
    vector<vector<int>> arrs(n, vector<int>());

    for (unsigned i = 0; i < n; ++i) {
        cin >> size;
        arrs[i].resize(size);

        for (int& item: arrs[i]) cin >> item;
    }

    for (unsigned i = 0; i < q; ++i) {
        cin >> q1 >> q2;
        cout << arrs[q1][q2] << '\n';
    }

    return 0;
}
