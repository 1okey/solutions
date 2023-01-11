// https://leetcode.com/problems/count-of-matches-in-tournament

impl Solution {
    pub fn number_of_matches(n: i32) -> i32 {
        let mut teams = n;
        let mut matches = 0;
        while teams > 1 {
            if teams % 2 == 1 {
                matches += (teams - 1) / 2;
                teams = (teams - 1) / 2 + 1;
            } else {
                matches += teams / 2;
                teams /= 2;
            }
        }
        matches
    }
}