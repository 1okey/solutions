#include <iostream>
#include <vector>

using std::vector;

static int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums.front()) {
            return 0;
        }
        
        if(target > nums.back()) {
            return nums.size();
        }
        
        uint16_t pos = 0;
        for(uint16_t i = 0, j = 1; j < nums.size(); i = j++) {
            if(target > nums[i] && target <= nums[j]){
                pos = j;
                break;
            }
        }
        
        return pos;
    }
};