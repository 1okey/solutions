class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0) return;
        
        for(size_t i = 0, j = s.size() - 1;
            i <= s.size() / 2 && i <= j;
            ++i, --j){
            
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};