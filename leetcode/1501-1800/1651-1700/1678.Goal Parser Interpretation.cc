// https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(const string& command) const noexcept {
        string output;
        unsigned len = command.size();
        for (int i = 0; i < len; ++i) {
            if (command[i] == 'G') {
                output += 'G';
            } 
            else if (i - len > 1 && command[i] == '(') {
                if (command[i + 1] == ')') {
                    output += 'o';
                    i += 1;
                } 
                else if (command[i + 1] == 'a') {
                    output += "al";
                    i += 2;
                }
            }
        }
        
        return output;
    }
};