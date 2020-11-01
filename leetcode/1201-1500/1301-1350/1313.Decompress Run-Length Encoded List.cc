// https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> output;
        output.reserve(nums.size());
        for(unsigned i = 0; (2 * i + 1) < nums.size(); ++i)
        {
            int freq = nums[2 * i];
            int val = nums[2 * i + 1];
            while(freq != 0) {
                output.push_back(val);
                --freq;
            }
        }
        return move(output);
    }
};