// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> output;
        output.reserve(n);

        int sum = 0;
        for(int i = 1; i <= n - 1; ++i){
            output.push_back(i);
            sum += i;
        }

        output.push_back(-sum);
        
        return move(output);
    }
};