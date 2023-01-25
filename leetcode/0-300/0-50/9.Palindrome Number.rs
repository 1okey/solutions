// https://leetcode.com/problems/palindrome-number

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let num = x as i64;
        let mut up_div: i64 = 1;
        let mut down_div: i64 = 10;

        if x < 0 {
            return false;
        }

        while num / up_div  != 0 {
            up_div *= 10;
        }

        while up_div  > down_div {
            let upper = num % up_div / (up_div / 10);
            let lower = num % down_div / (down_div / 10);

            if upper != lower {
                return false;
            }

            up_div /= 10;
            down_div *= 10;
        }

        true
    }
}