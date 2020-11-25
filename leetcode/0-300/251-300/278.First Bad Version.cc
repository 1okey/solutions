// https://leetcode.com/problems/first-bad-version/

class Solution {
public:
    int firstBadVersion(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int low = 1;
        int high = n;
        int guess = 0;
        while(true) {
            guess = ((long)low + high) / 2;
            
            if (guess == low) { // if guess starts loop
                return isBadVersion(low) ? low : high;
            }
            
            bool is_bad = isBadVersion(guess);
            if (!is_bad) {
                low = guess;
            } else if (is_bad && !isBadVersion(guess -1)) {
                return guess;
            } else {
                high = guess;
            }
        }
    
        return low;    
    }
};