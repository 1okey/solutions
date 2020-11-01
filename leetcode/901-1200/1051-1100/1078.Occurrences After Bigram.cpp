#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


static const int opt = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 1;
}();

class Solution {
public:
    vector<string> findOcurrences
        (const string& text, const string& first, const string& second) {
        
        vector<string> output;
        size_t pos = 0;
        while(pos != text.size()) {

            size_t f_start = 0;
            size_t s_start = 0;

            while(text[pos] == first[f_start]) {
                ++pos; ++f_start;
            }

            if(text[pos] == ' ' && f_start == first.size() && pos < text.size()) ++pos;
            if(pos == text.size()) break;
            
            while(text[pos] == second[s_start]) {
                ++pos; ++s_start;
            }

            if(text[pos] == ' ' && s_start == second.size() && pos < text.size()) ++pos;
            if(pos == text.size()) break;

            // std::cout << f_start << ' ' << s_start << std::endl;
            // std::cout << std::boolalpha << (f_start == first.size() && s_start == second.size()) << ' ' ;            
            if(f_start == first.size() && s_start == second.size() && pos != text.size()){
                string third = "";
                while(text[pos] != ' ') third += text[pos++]; 
                
                output.push_back(third);
            }

            ++pos;
        }
        
        
        return output;
    }
};

int main() {
    Solution sol;
    vector<string> result = sol.findOcurrences("alice is a good girl she is a good student", "a", "good");
    for(auto& item: result) {
        std::cout << item << ' ';
    }
}