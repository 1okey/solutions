#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, type, num;
    vector<int> stack_;
    cin >> n;
    while (n != 0) {
        cin >> type;
        if (type == 1) {
            cin >> num;
            if (stack_.empty()) {
                stack_.push_back(num);
            } else {
                // even if current number is less then top (max) element 
                // we put top element again so than when we pop it we
                // will have appropriate max element
                stack_.push_back(max(stack_.back(), num)); 
            }
        }
        if (type == 2) {
            if (stack_.size() > 0) {
                stack_.pop_back();
            }
        }
        if (type == 3){
            cout << stack_.back() << '\n';
        }
        --n;
    }
    return 0;
}
