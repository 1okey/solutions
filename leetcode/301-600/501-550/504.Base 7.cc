// https://leetcode.com/problems/base-7/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string seven_based;
        bool neg = num < 0;
        num = abs(num);
        
        while(num != 0) {
            seven_based.insert(0, to_string(num % 7));
            num /= 7;
        }
        
        if (neg) {
            seven_based.insert(0, "-");
        }
        
        return seven_based;
    }
};