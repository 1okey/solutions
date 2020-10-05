// https://leetcode.com/problems/shuffle-the-array/submissions/

static bool x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled(nums.size());
        shuffled.clear();
        shuffled.push_back(nums[0]);

        for (unsigned i = 1, j = n; i != n && j < nums.size(); ++i, ++j)
        {
            shuffled.push_back(nums[j]);
            shuffled.push_back(nums[i]);
        }
        shuffled.push_back(nums[nums.size() - 1]);

        return move(shuffled);
    }
};