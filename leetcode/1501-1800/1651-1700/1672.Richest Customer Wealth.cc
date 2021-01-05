// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_ = 0;
        
        int from = accounts[0].size() - 1;
        
        for (int i = from; i > 0; --i) {
            for (vector<int>& acc : accounts) {
                acc[0] += acc[i];
            }
        }
        
                    
        for (vector<int>& acc : accounts) {
            max_ = max(max_, acc[0]);
        }
        
        return max_;
    }
};