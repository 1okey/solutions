class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int max_num = nums[0];
        set<int> distinct;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            max_num = max(max_num, nums[i]);
            distinct.insert(nums[i]);
        }

        auto it = distinct.rbegin();
        for (int pointer = 1; it != distinct.rend() && pointer < 3; ++it, ++pointer);

        return distinct.size() < 3 ? max_num : *(it);
    }
};

class Solution {
public:
    int thirdMax(vector<int>& n) {
        sort(n.begin(), n.end());
        n.erase(unique(n.begin(), n.end()), n.end());
        return n.size() < 3 ? n.back() : n[n.size() - 3];
    }
};