// https://leetcode.com/problems/destination-city/

class Solution {
public:
    using dict = unordered_map<string, string>;
    
    string destCity(vector<vector<string>>& paths) {
        dict dests;
        vector<string> stops;
        stops.reserve(paths.size() * 2);
        
        for (vector<string>& path: paths)
        {
            dests.insert({path[0], path[1]});
            stops.push_back(path[0]);
            stops.push_back(path[1]);
        }
        
        for (string& stop: stops)
        {
            if (dests.find(stop) == dests.end())
            {
                return stop;
            }
        }
        
        return paths[0][0];
    }

};