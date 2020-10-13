
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/po 

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int depth = 0;
        stack<char> parenth_stack;
        for(char c: s) {
            if (c == '(') 
            {
                parenth_stack.push('(');
                ++depth;
            }
            else if (c == ')') {
                parenth_stack.pop();
                max_depth = max(max_depth, depth);
                --depth;
            }
        }
        return max_depth;
    }
};