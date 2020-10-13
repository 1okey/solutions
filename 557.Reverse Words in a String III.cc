// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string output;
        
        while(ss.rdbuf()->in_avail())
        {
            ss >> word;
            reverse(word.begin(), word.end());
            output += word + (ss.rdbuf()->in_avail() ? " " : "");
        }
        
        return move(output);
    }
};