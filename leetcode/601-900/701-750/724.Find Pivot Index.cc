// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right = 0;
        int left = 0;
        
        for(int& n : nums) {
            right += n;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if (left * 2 == right - nums[i]) {
                return i; 
            }
            left += nums[i];
        }
        
        return -1;
    }
};