// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        map<int,int> registry = {{5,0},{10,0},{20,0}};
        
        for(int& bill: bills) {
            if (bill != 5) {
                
                int change = bill - 5;
                for(auto it = registry.rbegin(); it != registry.rend(); it = next(it))
                {
                    while (change >= it->first && it->second > 0) {
                        change -= it->first;
                        it->second -= 1;
                    };
                }

                if (change != 0) {
                    return false;
                }
            }
            
            registry[bill]++;
        }
        
        return true;
    }
};