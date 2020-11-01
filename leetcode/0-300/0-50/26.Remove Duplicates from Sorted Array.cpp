#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

static int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        size_t num_pos = 1;
        size_t i = 1;
        while(i < nums.size()) {
            if(nums[i] != nums[i - 1]) {
                nums[num_pos++] = nums[i];
            }
            ++i;
        }
        
        nums.resize(num_pos);
        return num_pos;
    }
};

void TestRemoveDuplicatesFromSortedArray() {
    vector<int> n = {0,0,1,1,1,2,2,3,3,4};
    vector<int> n1 = {1,1,2};
    vector<int> n2 = {2,2,2,2,2,2,2,3,4,4,4,4,4,5,6,7};

    Solution s;
    cout << s.removeDuplicates(n) << '-';
    for(auto item: n) cout << item << ' ';
    cout << endl;

    cout << s.removeDuplicates(n1) << '-';
    for(auto item: n1) cout << item << ' ';
    cout << endl;

    cout << s.removeDuplicates(n2) << '-';
    for(auto item: n2) cout << item << ' ';
    cout << endl;
}

int main() {
    TestRemoveDuplicatesFromSortedArray();
    return 0;
}