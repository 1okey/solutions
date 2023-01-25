//https://leetcode.com/problems/plus-one

impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut carry = 1;
        let mut plus_one = digits.iter().rev().map(|n| {
            let num = n + carry;
            if num > 9 {
                carry = num % 9
            } else {
                carry = 0
            }
            num % 10
        }).collect::<Vec<i32>>();

        plus_one.reverse();

        if carry > 0 {
            plus_one.insert(0, carry);
        }

        plus_one
    }
}