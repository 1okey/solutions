impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let mut shuffled = Vec::with_capacity(nums.len());
        for idx in 0..n {
            shuffled.push(nums[idx as usize]);
            shuffled.push(nums[(idx + n) as usize]);
        }
        shuffled
    }
}