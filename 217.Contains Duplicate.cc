// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(nums.begin(), nums.end());
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) {
                return true;
            }
        }
        

        return false;
    }
};

// or using set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> numset;
        for(int& num : nums)
        {
            if(numset.find(num) != numset.end()) {
                return true;
            }        
            numset.insert(num);
        }
        return false;
    }
};