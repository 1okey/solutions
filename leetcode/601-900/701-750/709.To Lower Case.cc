// https://leetcode.com/problems/to-lower-case/
class Solution {
public:
    string toLowerCase(string& str) {
        for(char& c: str) {
            c |= 0x20; // flipping 6th bit makes lower case letter an uppercase
        }
        return str;
    }
};

// A - 01000000 whereas a - 01100000 and 0x20 is 00100000