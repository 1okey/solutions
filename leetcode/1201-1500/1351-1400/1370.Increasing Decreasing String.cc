// https://leetcode.com/problems/increasing-decreasing-string/

class Solution {
public:
    string sortString(string s) {
        int chars[26] = {0};
        for(char c : s) chars[c - 0x61]++;
        
        string output(s.size(), ' ');
        int i = 0;
        while (i < s.size()) {
            for(int j = 0; j < 26; ++j) {
                if (chars[j] > 0) {
                    output[i++] = (char)(j + 0x61);
                    chars[j]--;
                }
            }
            for(int j = 25; j >= 0; --j) {
                if (chars[j] > 0) {
                    output[i++] = (char)(j + 0x61);
                    chars[j]--;
                } 
            }
        }
        
        return output;
    }
};