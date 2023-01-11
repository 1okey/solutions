// https://leetcode.com/problems/count-the-number-of-consistent-strings

impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        words.iter().map(|word| {
            if word.chars().any(|ch| !allowed.contains(ch)) {
                0
            } else {
                1
            }
        }).sum()
    }
}