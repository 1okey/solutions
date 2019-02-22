static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        for(int& n : findNums){
            if(n == nums.back()){
                n = -1;
                continue;
            }
            
            auto it = find(nums.begin(), nums.end(), n);
            while(it != nums.end()){
                if(*it > n){
                    n = *it;
                    break;
                }
                it++;
            }
            if(it == nums.end()) n = -1;
        }
        return findNums;
    }
};
