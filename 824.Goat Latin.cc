class Solution {
public:
    bool isVowel(char c) {
        char lower = tolower(c);
        
        return lower == 'a' || lower == 'o' || lower == 'u' || lower == 'e' || lower == 'i';
    }
    
    string toGoatLatin(string s) {
        istringstream ss(s);
        int i = 1;
        string output, word;
        while(ss.rdbuf()->in_avail())
        {
            ss >> word;
            
            if (isVowel(word[0])) {
                output += word;
            } else {
                output += word.substr(1) + word[0];
            }
            
            output += "ma";
            output += string(i, 'a');
            output += ss.rdbuf()->in_avail() ? " " : "";
            ++i;
        }
        
        return output;
    }
};