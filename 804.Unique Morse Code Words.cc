#include <set>
#include <string>
#include <vector>


static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

const static vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> unique;
        for(auto& word : words){
            string morse = "";
            for(char c : word){
                morse += dict[c- 97];
            }
            unique.insert(morse);
        }
        return unique.size();
    }
};
