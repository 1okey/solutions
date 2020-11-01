// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t last = nums.size() - 1; 
        return (nums[last] - 1) * (nums[last - 1] - 1);
    }
};