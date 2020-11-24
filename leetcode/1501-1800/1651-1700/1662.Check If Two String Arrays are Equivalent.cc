// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1_ptr = 0, w2_ptr = 0;
        int s1_ptr = 0, s2_ptr = 0;
        
        
        char lhs, rhs;
        while(w1_ptr != word1.size() && w2_ptr != word2.size()) {
            lhs = word1[w1_ptr][s1_ptr];
            rhs = word2[w2_ptr][s2_ptr];

            if (lhs != rhs || (w1_ptr == word1.size() && w2_ptr == word2.size())) {
                return false;
            }
            
            ++s1_ptr;
            ++s2_ptr;
            if(s1_ptr == word1[w1_ptr].size()) {
                s1_ptr = 0;
                ++w1_ptr;
            }
            
            if(s2_ptr == word2[w2_ptr].size()) {
                s2_ptr = 0;
                ++w2_ptr;
            }
        }
        
        return w1_ptr == word1.size() && w2_ptr == word2.size();
    }
};