// https://leetcode.com/problems/unique-morse-code-words/

const static vector<string> alphabet = {
    ".-","-...","-.-.","-..",
    ".","..-.","--.","....",
    "..",".---","-.-",".-..",
    "--","-.","---",".--.",
    "--.-",".-.","...","-",
    "..-","...-",".--","-..-",
    "-.--","--.."
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> transformations;
        for (string& word: words)
        {
            transformations.insert(transform(word));
        }
        
        return transformations.size();
    }
    
    string transform(const string& word)
    {
        string morse;
        
        for (size_t i = 0; i < word.size(); ++i)
        {
            morse += alphabet[(int)(word[i] - 0x61)];
        }

        return move(morse);
    }
};