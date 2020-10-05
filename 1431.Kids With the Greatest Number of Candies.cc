// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandies = *(max_element(candies.begin(), candies.end()));
        vector<bool> isGreatestNum = vector<bool>(candies.size(), false);
        
        for (unsigned i = 0; i < candies.size(); ++i)
        {
            if (candies[i] + extraCandies >= maxCandies) {
                isGreatestNum[i] = true;
            }
        }
        
        return move(isGreatestNum);
    }
};