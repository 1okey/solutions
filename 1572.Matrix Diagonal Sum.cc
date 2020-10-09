// https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        size_t size = mat[0].size();
        for (size_t i = 0; i < size; ++i) {
            if (size - i - 1 != i) {
                sum +=  mat[size - i - 1][i];
            } 
            sum += mat[i][i];
        }
        
        return sum;
    }
};