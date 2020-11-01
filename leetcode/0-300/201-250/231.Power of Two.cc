// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = n;
        bool isPower = false;
        
        while(num != 0) {
            if (!isPower && (num & 0x01)) {
                isPower = true;
            } else if (isPower && (num & 0x01)) {
                return false;
            }
            num >>= 1;        
        } 
        
        return true && isPower;
    }
};