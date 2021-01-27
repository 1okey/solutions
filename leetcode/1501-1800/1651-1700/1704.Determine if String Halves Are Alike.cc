// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        
        int right = s.size() / 2;
        int left = right - 1;
        int count = 0;

        while(left >= 0 && right < s.size()) {
            count += vowels.find(tolower(s[left--])) != vowels.end();
            count -= vowels.find(tolower(s[right++])) != vowels.end();
        } 
        
        return count == 0;
    }
};


int main()
{
    Solution s = Solution();
    cout << (s.halvesAreAlike("boOk") ? "yes" : "no") << '\n';
    cout << (s.halvesAreAlike("nookie")  ? "yes" : "no") << '\n';
    cout << (s.halvesAreAlike("no") ? "yes" : "no") << '\n';
    cout << (s.halvesAreAlike("noob") ? "yes" : "no") << '\n';
    cout << (s.halvesAreAlike("cobb") ? "yes" : "no") << '\n';

}