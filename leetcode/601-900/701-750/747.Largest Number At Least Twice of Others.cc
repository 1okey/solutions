class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> doubles;
        doubles.reserve(nums.size());
        
        int max_ = nums[0];
        int idx = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (max_ < nums[i]) {
                max_ = nums[i];
                idx = i;
            }
            doubles.push_back(nums[i] * 2);
        }
        
        for(int& d: doubles) {
            if (d > max_ && max_ * 2 != d) {
                return -1;
            }
        }
        
        return idx;
    }
};