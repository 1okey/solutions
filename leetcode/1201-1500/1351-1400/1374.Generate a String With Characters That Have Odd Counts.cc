// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
class Solution {
public:
    string generateTheString(int n) {
        string output;
        output.reserve(n);
        
        char start = 'a';
        int shift = 0x0;
        int acc = 0;
        int i = 1;
        
        while (acc != n)
        {
            if (n - (acc + i) >= 0)
            {
                acc += i;
                output += string(i, (char)start + shift);
                ++shift;
            }
            
            i += n - (acc + i) < 0 ? -2 : 2;
        }

        
        return output;
    }
};