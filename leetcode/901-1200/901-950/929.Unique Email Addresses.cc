// https://leetcode.com/problems/unique-email-addresses/submissions/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        
        string em;
        em.reserve(emails[0].size());

        for(string& e: emails){
            bool plus = false;
            bool at = false;
            
            for(size_t i = 0; i < e.size(); ++i){
                if(e[i] == '@'){
                  plus = false;
                  at = true;
                }

                if((e[i] == '.' && !at) || plus) continue;

                if(plus = e[i] == '+') continue;

                em += e[i];
            }
            
            unique.insert(em);
            em.clear();
        }
        
        return unique.size();
    }
};

