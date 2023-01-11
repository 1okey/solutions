// https://leetcode.com/problems/count-the-digits-that-divide-a-number

impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        let mut div = 1;
        let mut count = 0;
        while num / div > 0 {
            if num % (num % (div * 10) / div) == 0 {
                count += 1;
            }
            div *= 10;
        }

        count
    }
}

impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        num.to_string().chars().map(|d| {
            if num % (d.to_digit(10).unwrap() as i32) == 0 {
                1
            } else {
                0
            }
        }).sum()
    }
}