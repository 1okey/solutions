static int unsync = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n) {
            std::cout << n << " ";
            n = n/5;
            result += n;
        }
        return result;
    }
};
