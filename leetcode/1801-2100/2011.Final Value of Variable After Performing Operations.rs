// https://leetcode.com/problems/final-value-of-variable-after-performing-operations

impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut result = 0;
        for op in operations {
            match op.as_str() {
                "--X" | "X--" => result-=1,
                "++X" | "X++" => result+=1,
                _ => (),
            };
        }
        result
    }
}

impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        operations.iter().fold(0, |acc, op| {
            if op.contains('+') { acc + 1 } else { acc - 1}
        })
    }
}