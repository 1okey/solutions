// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int from = 0;
        int to = s.size() - 1;
        int size = 0;
        
        while(s[from] == ' ') ++from;
        while(s[to] == ' ') --to;
        while(s[to - size] != ' ' && to - size >= from) ++size;
        
        return size;
    }
};