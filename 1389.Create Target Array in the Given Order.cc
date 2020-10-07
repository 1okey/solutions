// https://leetcode.com/problems/create-target-array-in-the-given-order/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        target.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) 
        {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return move(target);
    }
};