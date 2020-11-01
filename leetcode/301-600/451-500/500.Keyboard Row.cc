class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<char>> rows = {
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'},
        };
        
        vector<string> output;
        
        for(string& word: words)
        {
            vector<char> target_row;
            for(vector<char>& row: rows)
            {
                if (find(row.begin(), row.end(), tolower(word[0])) != row.end()) {
                    target_row = row;
                    break;
                }
            }
            
            size_t i = 1;
            while(find(target_row.begin(), target_row.end(), tolower(word[i])) != target_row.end() && i < word.size())
            {
                ++i;
            }
            
            if (i == word.size()) {
                output.push_back(word);
            }
        }
        
        return output;
    }
};