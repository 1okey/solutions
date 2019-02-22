static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int min = 0, max = s.length();
        
        result.push_back(s.front() == 'I' ? min++ : max--);
        
        for(size_t i = 1, j = 0; i < s.length(); j = i++){
            if(s[j] == s[i])
                result.push_back(s[j] == 'D' ? max-- : min++);
            else
                result.push_back(s[j] == 'D' ? min++ : max--);
        }
        
        result.push_back(s.back() == 'I' ? min++ : max--);
        
        return result;
    }
};
