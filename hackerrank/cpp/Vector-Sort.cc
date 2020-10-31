// https://www.hackerrank.com/challenges/vector-sort/problem

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;
    vector<int> v(size);
    for(int & i : v) cin >> i;
    sort(v.begin(), v.end());
    for(int & i : v) cout << i << ' ';
    return 0;
}
