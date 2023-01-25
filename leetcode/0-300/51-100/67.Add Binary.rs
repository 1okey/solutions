// https://leetcode.com/problems/add-binary

impl Solution {
    pub fn add_binary(lhs: String, rhs: String) -> String {
        let mut a = lhs.clone();
        let mut b = rhs.clone();
        let diff: i32 = ((a.len() as i32) - b.len() as i32);
        if diff > 0 {
            b.insert_str(0, (0..diff).map(|_| "0").collect::<String>().as_str());
        } else if diff < 0  {
            a.insert_str(0, (0..diff.abs()).map(|_| "0").collect::<String>().as_str());
        }

        let mut carry = 0;
        let mut output = a.chars().rev()
            .map(|ch| ch.to_digit(10).unwrap())
            .zip(b.chars().map(|ch| ch.to_digit(10).unwrap()).rev())
            .map(|(x, y)| {
                let result = (x + y + carry) % 2;
                carry = (y + x + carry) / 2;
                char::from_digit(result, 10).unwrap()
        }).collect::<String>();


        if carry > 0 {
            let top = output.pop().unwrap();
            if top == '1' {
                output.push_str("11");
            } else {
                output.push_str("01");
            }
        }

        output.chars().rev().collect::<String>()
    }
}