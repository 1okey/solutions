// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> output;
        output.reserve(s.size());
        int i = s.size() - 1;
        int ch = 0;
        while(i >= 0)
        {
            if (s[i] == '#') {
                ch = stoi(s.substr(i - 2, 2));
                i -= 3;
            } else {
                ch = s[i] - '0';
                --i;
            }
            
            output.insert(output.begin(), (char)(ch + 0x60));
        }

        return string(output.begin(), output.end());
    }
};