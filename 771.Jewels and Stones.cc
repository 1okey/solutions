// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewels = 0;
        for (char& j : J) 
        {
            jewels += count(S.begin(), S.end(), j);
        }
        return jewels;
    }
};