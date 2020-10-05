// https://leetcode.com/problems/number-of-good-pairs/

static bool x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int counter = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            counter += count(it + 1, nums.end(), *it);
        }
        return move(counter);
    }
};