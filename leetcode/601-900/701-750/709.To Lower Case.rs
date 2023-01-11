// https://leetcode.com/problems/to-lower-case

impl Solution {
    pub fn to_lower_case(s: String) -> String {
        s.chars().map(|ch| ch.to_lowercase().to_string()).collect::<String>()
    }
}