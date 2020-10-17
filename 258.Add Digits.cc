// https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int number) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int start = number;
        int acc = 0;
        while (start / 10 != 0)
        {
            acc = start;
            start = 0;
            while(acc != 0)
            {
                start += acc % 10;
                acc /= 10;
            }
        }
        
        return start;
    }
};