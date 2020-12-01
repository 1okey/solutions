// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        stack<char> s_stack;
        for(char c: S) {
            if (c == '#' && s_stack.size() > 0) {
                s_stack.pop();
            } else if (c != '#') {
                s_stack.push(c);
            }
        }
        
        stack<char> t_stack;
        for(char c: T) {
            if (c == '#' && t_stack.size() > 0) {
                t_stack.pop();
            } else if (c  != '#') {
                t_stack.push(c);
            }
        }
        
        return s_stack == t_stack;
    }
};