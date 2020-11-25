#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) {
            return "";
        }
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        string common = "";
        int word_ptr = 0, char_ptr = 0;
        
        while(true) {
            char current = strs[word_ptr][char_ptr];
            
            for(int i = word_ptr; i < strs.size(); ++i) {
                string& word = strs[i];
                if (char_ptr == word.size() || word[char_ptr] != current) {
                    return common;
                }
            }
            
            common += current;
            ++char_ptr;
            word_ptr = 0;
        }
        
        return common;
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

