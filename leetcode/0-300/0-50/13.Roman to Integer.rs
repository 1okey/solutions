// https://leetcode.com/problems/roman-to-integer

use std::collections::HashMap;

impl Solution {

    pub fn roman_to_int(s: String) -> i32 {
        let dict: HashMap<char, i32> = HashMap::from([
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]);
        
        let mut prev = *dict.get(&s.chars().nth(0).unwrap()).unwrap();
        let mut arabic = prev;

        for (idx, n) in s[1..].to_string().chars().map(|ch| *dict.get(&ch).unwrap()).enumerate() {
            arabic += n;
            if n > prev {
                arabic -= (prev * 2);
            }
            prev = n;
        }

        arabic as i32
    }
}