// https://leetcode.com/problems/number-of-good-pairs

impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut counter = [0;101];
        for n in nums {
            counter[n as usize] += 1
        }

        let mut sum = 0;
        for c in counter {
            sum += c * (c - 1) / 2;
        }

        sum
    }
}