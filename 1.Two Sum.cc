// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// 
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
// Example:
// 
// Given nums = [2, 7, 11, 15], target = 9,
// 
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


static int x=[](){
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int>m;
        int n1 = 0 ,n2 = 0;
        for(size_t i = 0; i < nums.size(); ++i){
            m.insert({nums[i], i});
            int complement = target - nums[i];
            if(m.find(complement) != m.end() && i != m[complement]){
                n1 = m[complement];
                n2 = i;
                break;
            }
        }
        return {n1,n2};
    }
};
