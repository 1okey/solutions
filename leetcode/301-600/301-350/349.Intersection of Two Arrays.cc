// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> vals;
        for(int n: nums1) {
            vals.insert(n);
        }
        
        unordered_set<int> intersection;
        for(int n: nums2) {
            if(vals.find(n) != vals.end()) {
                intersection.insert(n);
                vals.erase(n);
            }
        }
        
        return vector<int>{intersection.begin(), intersection.end()};
    }
};