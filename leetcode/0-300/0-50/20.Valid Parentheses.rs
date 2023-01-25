// https://leetcode.com/problems/valid-parentheses

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = vec!();
        for ch in s.chars() {
            match ch {
                '(' | '[' | '{' => stack.push(ch),
                ')' | ']' | '}' => {
                    if let Some(last) = stack.last() {
                        if (*last == '(' && ch != ')') || 
                            (*last == '[' && ch != ']') || 
                            (*last == '{' && ch != '}') 
                        {
                            return false;
                        }    
                        stack.pop();
                        continue;
                    }

                    return false
                }
                _ => continue,
            }
        }
        return stack.len() == 0
    }
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = vec!();
        for ch in s.chars() {
            match ch {
                '(' => stack.push(')'),
                '[' => stack.push(']'),
                '{' => stack.push('}'),
                ')' | ']' | '}' => if Some(ch) != stack.pop() { return false; }
                _ => continue,
            }
        }
        return stack.is_empty()
    }
}