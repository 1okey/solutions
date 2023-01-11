// https://leetcode.com/problems/build-array-from-permutation

impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::with_capacity(nums.len());
        for n in 0..nums.len() {
            result.push(nums[nums[n as usize] as usize]);
        }
        result
    }
}