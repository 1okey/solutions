// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int amount = 0;
        while (n != 0)
        {
            amount += n & 0x1;
            n >>= 1;
        }
        return amount;
    }
};