// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(const string& allowed, vector<string>& words) {
        int map[26] = {0};
        for(char c : allowed) {
            map[c - 0x61]++;
        }
        
        int counter = 0;
        for (string& word: words) {

            int i = 0;
            for (i = 0; i < word.size(); ++i) {
                if(map[word[i] - 0x61] == 0) {
                    break;
                }    
            }
            
            if (i == word.size()) {
                ++counter;
            }
        }
        
        return counter;
    }
};