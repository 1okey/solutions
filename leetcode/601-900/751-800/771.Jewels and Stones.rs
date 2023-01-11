// https://leetcode.com/problems/jewels-and-stones

use std::collections::HashSet;

impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let jwls = jewels.chars().collect::<HashSet<_>>();

        let mut matches = 0;
        for s in stones.chars() {
            if jwls.contains(&s) {
                matches += 1;
            }
        } 

        matches
    }
}