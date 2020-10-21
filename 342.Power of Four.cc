class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        while(n % 4 == 0) {
            n /= 4;
        }
        
        return n == 1;
    }
};

// or constant time solution

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        return floor(log10(n) / log10(4)) == ceil(log10(n) / log10(4)) 
    }
};

