// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int planted = n;
        
        for(size_t i = 0; i < flowerbed.size() && planted != 0;)
        {
            if (flowerbed[i] == 1) {
                i += 2;
            } 
            else if (i + 1 < flowerbed.size() && flowerbed[i + 1] == 1) {
                i += 3;
            }
            else {
                --planted;
                i += 2;
            }
        }
        
        return planted == 0;
    }
};