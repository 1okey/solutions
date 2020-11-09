// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(m, 0));
        int x,y;
        
        for (vector<int>& ind : indices) {
            x = ind[0];
            y = ind[1];
            
            for (size_t i = 0; i < m; ++i) {
                mat[x][i]++;
            }
            
            for (size_t i = 0; i < n; ++i) {
                mat[i][y]++;
            }
        }
        
        int odd_count = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                odd_count += mat[i][j] % 2 == 1;
            }
        }
        
        return odd_count;
    }
};