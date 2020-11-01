static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> dict;
        vector<string> uncommon;
        size_t pos = 0;
        while(pos != string::npos){
            pos = A.find_first_of(' ');
            dict[A.substr(0, pos)]++;
            A = A.substr(pos+1);
        }
        
        pos = 0;
        while(pos != string::npos){
            pos = B.find_first_of(' '); 
            dict[B.substr(0, pos)]++;
            B = B.substr(pos+1);
        }
        
        for(auto& pair: dict){
            if(pair.second == 1)
                uncommon.push_back(pair.first);
        }
        return uncommon;
        
    }
};

// or

class Solution {
public:
    void addWords(unordered_map<string, int>& dict, string& words)
    {
        istringstream is(words);
        while(is.rdbuf()->in_avail()){
            string word;
            is >> word;
            if (dict.find(word) == dict.end()){
                dict.insert({word, 1});
            } else {
                dict[word]++;
            }
        }
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> dict;
        addWords(dict, A);
        addWords(dict, B);

        vector<string> uncommon;
        for (auto& [key,value]: dict) {
            if (value == 1) {
                uncommon.push_back(key);
            }
        }
        
        return uncommon;
    }
};