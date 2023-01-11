// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|n| {
            nums.iter().filter(|&other| *other < *n).count() as i32
        }).collect::<Vec<i32>>()
    }
}