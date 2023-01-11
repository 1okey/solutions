// https://leetcode.com/problems/goal-parser-interpretation

impl Solution {
    pub fn interpret(command: String) -> String {
        command.replace("()","o").replace("(al)", "al")
    }
}

impl Solution {
    pub fn interpret(command: String) -> String {
        let mut result = String::new();
        let mut it = command.chars();
        let mut is_alpha = false;
        while let Some(c) = it.next() {
            let str = match c {
                'G' => "G",
                '(' => {
                    is_alpha = false;
                    continue                   
                },
                'a' => {
                    is_alpha = true;
                    "al"
                },
                ')' => if is_alpha { continue } else {is_alpha = false; "o"},
                _ => continue
            };

            result.push_str(&str.to_string());
        }

        result
    }
}