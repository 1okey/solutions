// https://leetcode.com/problems/concatenation-of-array

impl Solution {
    pub fn get_concatenation(mut nums: Vec<i32>) -> Vec<i32> {
        let mut result = (&nums).to_vec();
        for n in nums.iter() {
            result.push(*n);
        }
        result
    }
}