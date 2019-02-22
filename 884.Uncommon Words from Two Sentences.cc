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
