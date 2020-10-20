class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        while(n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }
};

// or constant time solution

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        return floor(log10(n) / log10(3)) == ceil(log10(n) / log10(3)) 
    }
};

