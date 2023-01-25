// https://leetcode.com/problems/number-of-1-bits

impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut num = n;
        let mut weight = 0;
        while num > 0 {
            if num & 0x1 == 0x1 {
                weight += 1;
            }
            num >>= 1;
        }
        weight
    }
}