impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut chars = [0;26];
        let mut b = [0; 2];

        for c in sentence.chars() {
            chars[((c as u32) - 97) as usize] += 1
        }
        
        for c in chars {
            if c == 0 {
                return false
            }
        }

        return true;
    }
}