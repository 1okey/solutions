static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result;
        for(size_t i = 0; i < S.length(); ++i){
            if(S[i] == C){
                result.push_back(0);
                continue;
            }
            for(size_t j = i; j < S.length(); ++j){
                if(S[j] == C){
                    int distance = !result.empty() && j - i > result.back() ? result.back() + 1 : j - i;
                    result.push_back(distance);
                    break;
                }
            }
            if(i == result.size()){
                result.push_back(result.back() + 1);
            }
        }
        return result;
    }
};
