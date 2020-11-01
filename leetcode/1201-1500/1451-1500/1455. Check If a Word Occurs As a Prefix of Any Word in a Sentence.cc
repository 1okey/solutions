// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution {
public:

    int isPrefixOfWord(const string& s, const string& w) const noexcept {
        int counter = 1;
        for(size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') ++counter;
            
            if (s[i] == w[0] && (i == 0 || s[i - 1] == ' ')) {
                int ptr = 0;
                
                while(ptr < w.size() && s[i + ptr] == w[ptr]) ++ptr;
                
                if (ptr == w.size()) return counter;
            }
        }
        
        return -1;
    }
};