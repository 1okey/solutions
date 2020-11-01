// https://leetcode.com/problems/flipping-an-image/submissions/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B;
        for(vector<int>& row : A)
        {
            vector<int> reversed(row.size());
            for(size_t i = 0; i < row.size(); ++i)
            {
                int bit = row[row.size() - i - 1];
                reversed[i] = !bit;
            }
            B.push_back(reversed);
        }
        return B;
    }
};