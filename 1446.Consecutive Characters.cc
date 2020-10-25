#include <cmath>

class Solution {
public:
    int maxPower(string s) {
        int max_power = 0;
        
        for(size_t i = 0; i < s.size(); ++i) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[j - 1]) ++j;
            max_power = max_power > j - i ? max_power : j - i;
        }
        
        return max_power;
    }
};