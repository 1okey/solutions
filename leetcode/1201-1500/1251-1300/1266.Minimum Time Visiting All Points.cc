// https://leetcode.com/problems/minimum-time-visiting-all-points/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int seconds = 0;
        for(size_t i = 1; i < points.size(); ++i)
        {
            seconds += getMaxDistanceBetweenPoints(points[i - 1], points[i]); 
        }
        return seconds;
    }
    
    int getMaxDistanceBetweenPoints(const vector<int>& from, const vector<int>& to)
    {
        // biggest difference between coordinates will 
        // be the ammount of seconds between points
        
        return (
            max(
                abs(from[0] - to[0]),
                abs(from[1] - to[1])
            )
        );
    }

};