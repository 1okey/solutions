// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int length = 0;
        int balance = 0;
        
        for (char c : s)
        {
            ++length;
            balance += c == 'L' ? -1 : 1;
            if (length > 0 && balance == 0)
            {
                ++count;
            }
        }
        
        return count;
    }
};