// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let mut sum = 0;
        let mut prod = 1;
        let mut div = 1;
        while n / div > 0 {
            sum += (n % (div * 10) / div);
            prod *= (n % (div * 10) / div);
            div *= 10;
        }

        prod - sum
    }
}