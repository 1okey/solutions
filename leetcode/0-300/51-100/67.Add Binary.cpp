// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

#include <string>
#include <iostream>

using std::string;

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string addBinary(string a, string b) {
        bool condition = a.size() > b.size();
        auto l_it = condition ? a.rbegin() : b.rbegin();
        auto l_end = condition ? a.rend() : b.rend();
        auto s_it = condition ? b.rbegin() : a.rbegin();
        auto s_end = condition ? b.rend() : a.rend();
        
        string result;
        int acc;
        int carry = 0;
        
        while(l_it != l_end) {
            acc = (*l_it - '0') + carry;
            if(s_it != s_end){
                acc += (*s_it - '0');
                ++s_it;
            }
            result.insert(result.begin(), acc % 2 == 1 ? '1' : '0');
            carry = acc > 1;
            l_it++;
        }
        if(carry)
            result.insert(result.begin(), '1');
        return result;
    }
};