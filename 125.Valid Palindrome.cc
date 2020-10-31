// https://leetcode.com/problems/valid-palindrome/submissions/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;

        for (size_t i = 0, j = s.size() - 1; i < j && i >= 0 && j < s.size(); ++i, --j)
        {

            while (!isalnum(s[i]) && i < j) ++i;
            while (!isalnum(s[j]) && j > i) --j;
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
        }
        
        return true;
    }
};