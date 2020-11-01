class Solution {
public:
    string reverseOnlyLetters(string S) {
        
        vector<char> buff(S.size());
        int i = 0;
        int j = S.size() - 1;
        
        while (i < S.size())
        {
            if(isalpha(S[i])) {
                while(!isalpha(S[j])) --j;
                buff[i] = S[j];
                --j;
            } else {
                buff[i] = S[i];
            }
            
            ++i;
        }
        
        return string{buff.begin(), buff.end()};
    }
};