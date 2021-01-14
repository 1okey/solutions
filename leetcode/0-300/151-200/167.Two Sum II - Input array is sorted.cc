// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> compliment;
        
        for(int i = 0; i < numbers.size(); ++i) {
            compliment[target - numbers[i]] = i + 1;
        }
        
        for(int i = 0; i < numbers.size(); ++i) {
            auto it = compliment.find(numbers[i]);
            if(it != compliment.end() && it->second != i + 1) {
                int first = it->second;
                int second = i + 1;
                if (first < second) return {first,second};
                else return {second, first};
            }
        }
        
        return {0, 0};
    }
};