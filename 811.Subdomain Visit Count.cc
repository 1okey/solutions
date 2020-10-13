// https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> visits;
        for (const string& domain: cpdomains)
        {
            int space_index = domain.find_first_of(' ');
            int ammount = stoi(domain.substr(0, space_index));
            string domain_view = domain.substr(space_index + 1);
            while (domain_view.size() > 0)
            {
                if (visits.find(domain_view) == visits.end())
                {
                    visits.insert({domain_view, ammount});
                }
                else {
                    visits[domain_view] += ammount;
                }
                
                int to = domain_view.find_first_of('.');
                
                if (to == string::npos) break;
                
                domain_view = domain_view.substr(to + 1);
            }
        }
        
        vector<string> output;
        for (auto [key, value]: visits)
        {
            output.push_back(to_string(value) + " " + key);
        }
        
        return move(output);
    }
};