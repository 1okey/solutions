// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(int& n : nums)
        {
            int base = floor(log10(n)) + 1;
            counter += ((base % 2) == 0); // logarithm with base 10 of number will return in which base 10 should be put to get this number
        }
        return counter;
    }
};