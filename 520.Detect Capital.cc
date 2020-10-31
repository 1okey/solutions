class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if(word.size() == 1) {
            return true;
        }
        
        bool isCapital = word[0] <= 0x5B;
        bool isUppercase = word[1] <= 0x5B;
        
        for (size_t i = 2; i < word.size(); ++i) {
            if (isUppercase && word[i] >= 0x5B || !isUppercase && word[i] <= 0x5B) {
                return false;
            }
        }
        
        return isCapital && isUppercase || !isCapital && !isUppercase || isCapital && !isUppercase;
    }
};

// or cleaner but a bit slower solution :

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_count = 0;
        for (char c: word) {
            capital_count += c <= 0x5b;
        }
        
        return capital_count == 0 || capital_count == word.size()
             || capital_count == 1 && word[0] <= 0x5b;
    }
};