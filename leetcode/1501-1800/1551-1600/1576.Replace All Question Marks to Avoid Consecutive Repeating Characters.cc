// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

class Solution {
public:
    string modifyString(string s) {
        
        for (size_t i = 0, bound = s.size(); i < bound; ++i) {
            if(s[i] == '?') {
                for (char ch : "abc") { // use "abc" since it's quaranteed there won't be consecutive characters in input string
                    if (i == 0 && s[i + 1] != ch) {
                        s[i] = ch;
                        break;
                    }
                    else if (i + 1 == s.size() && s[s.size() - 2] != ch) {
                        s[s.size() - 1] = ch;
                        break;
                    }
                    else if (s[i + 1] != ch && s[i - 1] != ch) {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        
        return s;
    }
};