// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int height  = 0;
        int max_ = height;
        for (int& g : gain) {
            height += g;
            max_ = max(height, max_);
        }
        
        return max_;
    }
};