// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int q, q_type, n;
    set<int> ns;
    cin >> q;
    while(q != 0) {
        cin >> q_type >> n;
        switch(q_type) {
            case 1: ns.insert(n); break;
            case 2: ns.erase(n); break;
            case 3: cout << (ns.find(n) == ns.end() ? "No" : "Yes") << '\n'; break;
        }
        --q;
    }
    return 0;
}



