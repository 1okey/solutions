// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int max_consecutive = 0;
        int counter = 0;
        for (int& n: nums) {
            if (n == 1) {
                ++counter;
            } 
            else {
                max_consecutive = max(max_consecutive, counter);
                counter = 0;
            }
        }
        max_consecutive = max(max_consecutive, counter);
        return max_consecutive;
    }
};