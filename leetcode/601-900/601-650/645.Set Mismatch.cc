// https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> occurences(nums.size(), 0);
        for(int& n : nums) {
            occurences[n - 1]++;
        };
        
        vector<int> fix(2,0);
        for(size_t i = 0; i < nums.size(); ++i) {
            if (occurences[i] > 1) {
                fix[0] = i + 1;
            }
            if (occurences[i] == 0) {
                fix[1] = i + 1;
            }
        }
        
        return fix;
    }
};