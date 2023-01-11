// https://leetcode.com/problems/word-pattern

use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut k_to_v: HashMap<char, String> = HashMap::new();
        let mut v_to_k: HashMap<&str, char> = HashMap::new();

        if s.split_whitespace().count() != pattern.chars().count() {
            return false;
        }

        for (idx, w) in s.split_whitespace().enumerate() {
            if let Some(ch) = pattern.chars().nth(idx) {
                if !k_to_v.contains_key(&ch) {
                    k_to_v.insert(ch, w.to_string());
                    if v_to_k.contains_key(&w) {
                        return false;
                    }
                    v_to_k.insert(&w, ch);
                }

                if let Some(other) = k_to_v.get(&ch) {
                    if !other.eq(w) {
                        return false;
                    }
                }
            }
        }

        true
    }
}