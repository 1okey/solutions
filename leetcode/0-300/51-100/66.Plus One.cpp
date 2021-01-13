class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size() - 1;
        while (carry != 0 && i >= 0) {
            digits[i] += carry;
            carry = 0;
            if (digits[i] > 9) {
                carry = digits[i] % 9;
                digits[i] = 0;
            } else break;
            --i;
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};