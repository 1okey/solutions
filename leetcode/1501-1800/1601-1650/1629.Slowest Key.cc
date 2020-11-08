// https://leetcode.com/problems/slowest-key/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int longest = releaseTimes[0];
        char key = keysPressed[0];
        
        int delta = 0;
        for(size_t i = 1; i < releaseTimes.size(); ++i){
            int delta = releaseTimes[i] - releaseTimes[i - 1];
            if (delta >= longest) {
                key = delta > longest ? keysPressed[i] : max(key,  keysPressed[i]);
                longest = delta;
            }
        }
        
        return key;
    }
};