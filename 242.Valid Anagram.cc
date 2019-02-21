static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> s_c;
        map<char,int> t_c;
        for(auto s_it = s.begin(), t_it = t.begin();
           s_it != s.end() && t_it != t.end();
           ++s_it, ++t_it){
            s_c[*s_it]++;
            t_c[*t_it]++;
        }
        return s_c == t_c;
    }
};
