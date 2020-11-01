// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int div = 10;
        
        while (n != 0) {
            int num = n % div;
            product *= num;
            sum += num;
            n /= div;
        }
        
        return product - sum;
    }
};