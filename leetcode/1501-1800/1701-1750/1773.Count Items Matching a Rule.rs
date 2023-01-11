// https://leetcode.com/problems/count-items-matching-a-rule
impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        let mut count = 0;
        for i in items {
            if match rule_key.as_str() {
                "type" => i[0] == rule_value,
                "color" => i[1] == rule_value,
                "name" => i[2] == rule_value,
                _ => false,
            } {
                count += 1;
            }
        }

        count
    }
}


impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        use std::collections::HashMap;
        let mut count = 0;
        let map: HashMap<&str, usize> = HashMap::from([
            ("type", 0),
            ("color", 1),
            ("name", 2),
        ]);
        
        for i in items {
            if i[map[rule_key.as_str()]] == rule_value {
                count += 1;
            }
        }

        count
    }
}


impl Solution {
    pub fn idx_for_key(key: &String) -> usize {
        match key.as_str() {
            "type" => 0,
            "color" => 1,
            "name" => 2,
            _ => 0,
        }
    }

    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        items.iter().map(|i| if i[Solution::idx_for_key(&rule_key)] == rule_value { 1 } else { 0 }).sum()
    }
}
