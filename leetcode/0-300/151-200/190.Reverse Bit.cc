// https://leetcode.com/problems/reverse-bits/submissions/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int size = 32; // so that rest of bits are filled with 0s
        
        while (size != 0) {
            reversed <<= 1;
            reversed |= (n & 0x1);
            n >>= 1;
            --size;
        }
        
        return reversed;
    }
};