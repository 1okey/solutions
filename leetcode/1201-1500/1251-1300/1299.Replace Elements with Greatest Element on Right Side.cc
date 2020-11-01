// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> replaced;
        replaced.reserve(arr.size());
        
        for(auto it = arr.begin(); it + 1 != arr.end(); )
        {
            auto max_it = max_element(it + 1, arr.end());
            while (it != max_it) { // add max element until this element
                replaced.push_back(*max_it);
                ++it;
            }
        }
        
        replaced.push_back(-1);
        return replaced;
    }
};