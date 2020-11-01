// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> dict;
        for (size_t i = 0; i < arr.size(); ++i)
        {
            dict[arr[i]] += 1;
            dict[target[i]] -= 1;
        }
        
        for (auto& [key, val]: dict) {
            if (val != 0) return false;
        }
        
        return true;
    }
};