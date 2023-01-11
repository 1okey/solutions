impl Solution {
    pub fn running_sum(mut nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::with_capacity(nums.len());
        result.push(nums[0]);
        for idx in 1..nums.len() {
            result.push(nums[idx] + result[idx - 1]);
        }
        result
    }
}