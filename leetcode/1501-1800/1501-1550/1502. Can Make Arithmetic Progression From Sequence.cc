// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() == 2) return true;
        
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (size_t i = 1; i < arr.size(); ++i)
        {
            if (arr[i] - arr[i - 1] != diff) return false;
        }
        
        return true;
    }
};