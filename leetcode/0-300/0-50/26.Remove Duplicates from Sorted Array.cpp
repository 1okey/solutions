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
        int k = 0;

        if (nums.size() == 0) {
            return k;
        }
        
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]){
                nums[++k] = nums[i];
            }
        }
        
        return k + 1;
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