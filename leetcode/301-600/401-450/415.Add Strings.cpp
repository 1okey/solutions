// Given two non-negative integers num1 and num2 represented as string, 
// return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
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
    string addStrings(string a, string b) {
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
            
            result.insert(result.begin(), ('0' + acc % 10));
            carry = acc / 10;
            l_it++;
        }
        if(carry > 0)
            result.insert(result.begin(), ('0' + carry));
        return result;
    }
};