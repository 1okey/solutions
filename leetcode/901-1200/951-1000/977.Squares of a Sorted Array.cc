// Given an array of integers A sorted in non-decreasing order, return an array 
// of the squares of each number, also in sorted non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int k = 0;
        int l = A.size()-1;
        for (int i = A.size()-1; i >= 0; i--) {
            if (abs(A[k]) > abs(A[l])) {
                res[i] = A[k]*A[k++];
            } else {
                res[i] = A[l]*A[l--];
            }                
        }        
        return res;
    }
};
static int desyncIO = []()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    return 0;
}();
