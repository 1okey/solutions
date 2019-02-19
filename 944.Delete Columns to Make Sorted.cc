static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int min_delete = 0;
        for(size_t i = 0; i < A[0].length(); ++i){
            for(size_t j = 1; j < A.size(); ++j){
                if((A[j][i] - 'a') < (A[j-1][i] - 'a')){
                    ++min_delete;
                    break;
                }
            }
        }
        return min_delete;
    }
};
