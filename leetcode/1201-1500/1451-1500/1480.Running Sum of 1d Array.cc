// https://leetcode.com/problems/running-sum-of-1d-array/submissions/

static int x=[](){
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(unsigned i = 1; i < nums.size(); ++i) 
        {
            nums[i] += nums[i - 1];
        }
        return move(nums);
    }
};