// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> output;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (groups.find(groupSizes[i]) == groups.end()) {
                groups[groupSizes[i]] = vector<int>{};
            }
            
            int size = groupSizes[i];
            if (groups[size].size() < size) {
                groups[size].push_back(i);
            } 

            if (groups[size].size() == size) {
                output.emplace_back(move(groups[size]));
                groups[size].resize(0);
            }
        }
                            
        return output;
    }
};