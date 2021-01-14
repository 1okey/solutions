// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        string output;
        
        string word;
        bool first = true;
        for (char c: s) {
            if(c == ' ' && word.size() > 0){
                output = word + (first ? "" : " ") + output;
                first = false;
                word.clear();
            } else if (c != ' ') {
                word += c;
            }
        }
        
        string sep = output.size() == 0 ? "" : " ";
        return word.size() > 0 ? word + sep + output : output;
    }
};