// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
public:
    int minPartitions(const string& n) const noexcept {
        int max_ = 0;
        
        for (unsigned i = 0; i < n.size(); ++i) {
            max_ = max(n[i] - '0', max_);
        }
        
        return max_;
    }
};