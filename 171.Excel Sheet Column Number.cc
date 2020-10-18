class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for(size_t i = 0; i < s.size(); ++i)
        {
            number += (s[s.size() - i - 1] - 0x40) * pow(26, i);
        }
        return number;
    }
};