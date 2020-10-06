// https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char newstr [100] = {};
        
        for(unsigned i = 0; i < s.size(); ++i) {
           newstr[indices[i]] = s[i];
        }
        
        return string(newstr, indices.size());
    }
};