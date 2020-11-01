class Solution {
public:
    int minOperations(vector<string>& logs) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int depth = 0;
        for(string& log: logs)
        {
            if(log == "../") {
                depth += depth > 0 ? -1 : 0;
            }
            else if (log == "./") continue;
            else ++depth;
        }
        return abs(depth);
    }
};