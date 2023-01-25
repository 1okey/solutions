// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array

impl Solution {
        pub fn digit_sum(n: i32) -> i32 {
            let mut sum = 0;
            let mut num = n;
            while num > 0 {
                 sum += num % 10;
                 num /= 10;
            }
            sum
        }
    
        pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
            let sum: i32 = nums.iter().sum();
            let digit_sum: i32 = nums.iter().fold(0, |acc, &n| {
                acc + Solution::digit_sum(n)
            });
                
            (sum - digit_sum).abs()
        }
}
