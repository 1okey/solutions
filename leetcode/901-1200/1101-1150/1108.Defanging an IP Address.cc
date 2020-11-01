// https://leetcode.com/problems/defanging-an-ip-address/submissions/

class Solution {
public:
    string defangIPaddr(string address) {
        char newstr [21] = {};
        unsigned size = 0;
        for (char& ch: address) 
        {
            if (ch == '.') {
                newstr[size++] = '[';
                newstr[size++] = ch;
                newstr[size++] = ']';
            }
            else 
            {
                newstr[size++] = ch;
            }
        }
        return string(newstr, size);
    }
};