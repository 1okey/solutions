static int sync = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int size = 26;
        for(char c : s){
            result *= size;
            result += c - (c & 0x40);
        }

        return result;
    }
};
