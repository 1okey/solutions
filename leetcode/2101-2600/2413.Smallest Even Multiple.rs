// https://leetcode.com/problems/smallest-even-multiple/

impl Solution {
    pub fn smallest_even_multiple(n: i32) -> i32 {
        if n % 2 == 0 { n } else { Solution::smallest_even_multiple(n * 2) }
    }
}