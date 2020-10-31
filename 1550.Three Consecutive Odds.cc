class Solution {
public:
    bool isOdd(int n) { return n % 2 == 1;}
    
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (size_t i = 2; i < arr.size(); ++i)
        {
            if (isOdd(arr[i]) && isOdd(arr[i - 1]) && isOdd(arr[i - 2])) return true;
        }
        return false;
    }
};