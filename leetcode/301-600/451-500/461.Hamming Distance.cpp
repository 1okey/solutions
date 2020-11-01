#include <iostream>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 1;
}();

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        while(x || y){
            diff += ((x & 0x1) != (y & 0x1));
            x >>= 1;
            y >>= 1;
        }
        return diff;
    }
};