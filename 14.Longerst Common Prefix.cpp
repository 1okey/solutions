#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

static int opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        
        if(strs.size() == 0) return prefix;
        
        size_t i = 0;
        while(true) {
            char c = strs[0][i];
            
            for(const string& s: strs) {
                if(i >= s.size() || s[i] != c){
                    return prefix;
                }
            }
            ++i;
            prefix += c;            
        }
        
        return prefix;
    }
};

void TestLongestCommonPrefix() {
    vector<string> input =  {"flower","flow","flight"};
    vector<string> input1 = {"car","carpenter","caterpillar"};
    vector<string> input2 = {"dog","god","odd"};
    vector<string> input3 = {"oooo","ooao","oooa"};

    Solution s;
    cout << std::boolalpha
         << s.longestCommonPrefix(input)  << '\n'
         << s.longestCommonPrefix(input1) << '\n'
         << s.longestCommonPrefix(input2) << '\n'
         << s.longestCommonPrefix(input3) << endl;
}

int main() {
    TestLongestCommonPrefix();
    return 0;
}

