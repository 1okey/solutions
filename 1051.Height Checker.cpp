#include <vector>
#include <algorithm>
#include <iostream>

using std::sort;
using std::vector;

static const int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> c_heights = heights;
        sort(c_heights.begin(), c_heights.end());
        
        unsigned counter = 0;
        
        for(unsigned i = 0; i < heights.size(); ++i) {
            counter += c_heights[i] != heights[i];
        }

        return counter;
    }
};