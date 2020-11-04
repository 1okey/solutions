// https://leetcode.com/problems/rearrange-spaces-between-words/

class Solution {
public:
    string reorderSpaces(string text) {
        int space_count = 0;
        int word_count = 0;
        int first_char = text.find_first_not_of(' ');
        vector<string> words;
        
        for (int i = 0; i < text.size();) {
            if (text[i] == ' ') {
                int j = i;
                while (text[j] == ' ') ++j;
                space_count += j - i;
                i = j;
            } else {
                int j = i;
                while(j < text.size() && text[j] != ' ') ++j;
                words.push_back(text.substr(i, j - i));
                ++word_count;
                i = j;
            }
        }
        
        string output;
        bool first = true;
        
        int space_size = word_count > 1 ? space_count / (word_count - 1) : 0;
        for(string& word: words) {
            output += (first  ? "" : string(space_size, ' ')) + word;
            first = false;
        }

        int rest = word_count > 1 ? space_count % (word_count - 1) : space_count;
        return output + string(rest, ' ');
    }
};