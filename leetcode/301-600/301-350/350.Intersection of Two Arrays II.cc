// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> dict;
        for(int n: nums1) {
            dict[n]++;
        }
        
        vector<int> intersection;
        for(int n: nums2) {
            if(dict[n] > 0) {
                intersection.push_back(n);
                dict[n]--;
            }
        }
        
        return intersection;
    }
};