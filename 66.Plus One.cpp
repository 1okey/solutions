static int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int>& plusOne(vector<int>& digits) {
        auto it = digits.rbegin();
        auto first = digits.rend() - 1;
        for(; it != digits.rend(); ++it) {
            if(*it == 9) {
                *it = 0;
                if(it == first) {
                    digits.insert(digits.begin(), 1);
                    break;
                } 
            } 
            else {
                *it += 1;
                break;
            }
        }
        return digits;
    }
};