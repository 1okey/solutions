// https://leetcode.com/problems/add-digits§

impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        let mut n = num;
        while n > 9 {
            let mut ncopy = n;
            let mut sum = 0;
            while ncopy > 0 {
                sum += ncopy % 10;
                ncopy /= 10;
            }
            n = sum;
        }
        n
    }
}