// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                int num = nums[i];
                nums[i] = 0;
                nums[k++] = num;
            }
        }
    }
};