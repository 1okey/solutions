// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = nums[0];
        int cnt = 1;
        
        for(int& num : nums) {
            if (num == number) ++cnt;
            else if (cnt == 1) number = num;
            else --cnt;                    
        }
        
        return number;
    }
};