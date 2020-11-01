// Given a string s, find the length of the longest substring without repeating characters.

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_seq = 0;
        int counter = 0;
        int char_index_map [255];
        memset(char_index_map, -1, sizeof(char_index_map));

        for (int i = 0; i < s.size();) {
            char c = s[i];
            if (char_index_map[c] >= 0) {
                // cout << i << " found"<< '\n';
                i = char_index_map[c] + 1;
                max_seq = max(max_seq,counter);
                counter = 0;
                memset(char_index_map, -1, sizeof(char_index_map));
            } else {
                // cout << i << " not found"<< '\n';
                ++char_index_map[c] = i;
                ++counter;
                ++i;
            }
        }

        return max(max_seq,counter);
    }
};