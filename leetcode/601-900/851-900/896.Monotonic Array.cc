// https://leetcode.com/problems/monotonic-array/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 3) return true;

        int j = 1;
        while(j < A.size() - 1 && A[j] == A[j - 1]) ++j;
        bool isDecreasing = A[0] > A[j];
        
        for(size_t i = 1; i < A.size(); ++i)
        {
            if (isDecreasing && A[i] <= A[i-1]) continue;
            if (!isDecreasing && A[i] >= A[i-1]) continue;

            else return false;
        }
        
        return true;
    }
};