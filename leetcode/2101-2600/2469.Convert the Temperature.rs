// https://leetcode.com/problems/convert-the-temperature

impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        return vec![
            (celsius as f64) + 273.15,
            (celsius as f64) * 1.80 + 32.00
        ];
    }
}