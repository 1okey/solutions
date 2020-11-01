// https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int n) {
        int max_gap = 0;
        int gap = 0;
        
        while(n != 0) {
            if (n & 0x1) {
                int number = n;
                gap = (number >>= 1) != 0; // if after shift number is eq to zero than there's no gap
                
                while (number % 2 == 0 && number != 0) { // until bits are zeroes and num is not zero
                    number >>= 1;
                    ++gap;
                }
                
                max_gap = max(max_gap, gap);
            } 
            
            n >>= 1;
        }
        
        return max_gap;
    }
};