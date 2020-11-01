// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int map[26] = {0};
        
        for (char& c: t) map[c - 0x61]++;
        for (char& c: s) map[c - 0x61]--;
        
        for(size_t i = 0; i < 26; ++i) {
            if (map[i] == 1) {
                cout << i << '\n';
                return i + 0x61;
            }
        }
        
        return 'a';
    }
};