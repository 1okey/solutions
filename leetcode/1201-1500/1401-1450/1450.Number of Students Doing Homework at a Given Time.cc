// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int counter = 0;
        for (size_t i = 0; i < startTime.size(); ++i)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
            {
                ++counter;
            }
        }
        return counter;
    }
};