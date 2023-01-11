// https://leetcode.com/problems/maximum-69-number

impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let mut max = num;
        let mut div = 10000;
        while div > 0 {
            if (max % (div * 10) / div) == 6 {
                return num + (div * 3)
            }
            div /= 10
        }
        max
    }
}