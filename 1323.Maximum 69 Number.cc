// https://leetcode.com/problems/maximum-69-number/submissions/

class Solution {
public:
    int maximum69Number (int n) {
        
        int exp = floor(log10(n)); // exp represents power of 10 - number of digits of input num
        int maximum = 0;
        int div = pow(10, exp);
        
        while(exp >= 0) {
            div = pow(10, exp);
            
            if(n / div == 6 ) {
                maximum += 9 * div;
                maximum += (n % div); 
                break;
            }

            maximum += n - (n % div);

            n %= div;
            --exp;
        }

        return maximum;
    }
};