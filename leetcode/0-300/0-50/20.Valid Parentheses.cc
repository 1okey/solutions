// https://leetcode.com/problems/valid-parentheses/
 
class Solution {
private:
    stack<char> l_parentheses;
private:
    bool isLefty(char p)
    {
        return p == '[' || p == '(' || p == '{';  
    }
    
    bool matches(char lhs, char rhs)
    {
        return lhs == '[' && rhs == ']'
            || lhs == '(' && rhs == ')'
            || lhs == '{' && rhs == '}';
    }
public:
    bool isValid(string s) {
        for(char c: s) {
            if (isLefty(c)) {
                l_parentheses.push(c);
            } else if(!l_parentheses.empty() && matches(l_parentheses.top(), c)) {
                l_parentheses.pop();
            } else {
                return false;
            }
        }
        
        return l_parentheses.empty();
    }
};