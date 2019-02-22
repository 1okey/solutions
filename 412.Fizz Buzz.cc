static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r(n);
        for(size_t i = 1; i <= n; ++i){
            if(i % 3 == 0)              r[i - 1] += "Fizz";
            if(i % 5 == 0)              r[i - 1] += "Buzz";
            else if(i % 3 && i % 5)     r[i - 1] = to_string(i);
        }
        return r;
    }
};
