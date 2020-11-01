// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> smaller_count(nums.size());
        for (unsigned i = 0; i < nums.size(); ++i) {
            int& cur_num = nums[i];
            smaller_count[i] = count_if(nums.begin(), nums.end(), [&cur_num](int& num){
                return cur_num > num;
            });
        }
        return move(smaller_count);
    }
};