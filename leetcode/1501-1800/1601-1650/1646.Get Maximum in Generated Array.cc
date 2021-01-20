// https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if (n == 0) {
            return 0;
        }
        
        int max_ = 1;
        vector<int> nums = {0,1};
        
        int from = 1;
        while(true) {
            if ((from * 2) <= n) {
                max_ = max(nums[from], max_);
                nums.push_back(nums[from]);
            } else break;
            
            if ((from * 2 + 1) <= n) {
                int num = nums[from + 1] + nums[from];
                max_ = max(num, max_);
                nums.push_back(num);
            } else break;
            
            ++from;
        }
        
        return max_;
    }
};