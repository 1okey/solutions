// https://www.hackerrank.com/challenges/arrays-introduction/problem

#include <iostream>

using namespace std;

int main() {
    uint16_t size;
    cin >> size;
    vector<uint16_t> v(size);
    
    for(auto & item: v) {
        cin >> item;
    }
    
    for(auto item: vector<uint16_t>(v.rbegin(), v.rend())){
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}
