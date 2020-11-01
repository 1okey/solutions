static int asynx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
     int repeatedNTimes(vector<int>& A) {
      for (auto i = 0; i < A.size() - 2; ++i)
        if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
      return A[A.size() - 1]; 
    }
};
