static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    bool isSelfDivisible(int n){
        int divisor = 1;
        int remainder = 0;
        while(n / divisor > 0){
            remainder = n % (divisor * 10);
            if(remainder == 0 || remainder / divisor == 0 || n % (remainder / divisor) != 0)
                return false;
            divisor *= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(; left <= right; ++left){
            if(isSelfDivisible(left))
                result.push_back(left);
        }
        return result;
    }
};
