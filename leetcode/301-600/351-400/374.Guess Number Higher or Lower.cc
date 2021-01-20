// https://leetcode.com/problems/guess-number-higher-or-lower/

class Solution {
public:
    int guessNumber(int n) {
        long left = 0;
        long right = n;
        
        while (left <= right) {
            long pick = (left + right) / 2;
            long result = guess(pick);
            if (result == -1) {
                right = pick - 1;
            } else if (result == 1) {
                left = pick + 1;
            } else {
                return pick;
            }
        }
        
        return -1;
    }
};