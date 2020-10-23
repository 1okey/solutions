class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int num = 0;
        
        for (int& n : nums)
        {
            num ^= n;
        }
        
        return num;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(size_t i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] == nums[i-1]) continue;
            else {
                return nums[i - 1];
            }
        }
        
        return nums[nums.size() - 1];
    }
};