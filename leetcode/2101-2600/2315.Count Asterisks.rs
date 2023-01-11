// https://leetcode.com/problems/count-asterisks

impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut count = 0;
        let mut should_skip = false;

        for ch in s.chars() {
            if ch == '|' {
                should_skip = !should_skip;
            }

            if should_skip {
                continue
            }

            if ch == '*' {
                count += 1
            }
        }

        count
    }
}