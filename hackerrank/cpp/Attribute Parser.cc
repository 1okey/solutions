// https://www.hackerrank.com/challenges/attribute-parser

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <utility>
#include <string>

using namespace std;

class Parser {
private:
    unordered_map<string, string> dict;
    vector<string> prefixes;
    int lines;
    int queries;
private:
    pair<string,string> getKeyValuePair(string str) {
        int eq_idx = str.find_first_of('=');
        int quotes_idx = str.find_first_of('"', eq_idx);
        int last_quotes = str.find_first_of('"', quotes_idx + 1);
        
        return {
            str.substr(0, eq_idx - 1), 
            str.substr(quotes_idx + 1, last_quotes - quotes_idx - 1)
        };
    }
    
public:
    Parser() = default;
    
    int parseTag(string& line, int cur_pos)
    {
        int j = cur_pos;
        while(isalnum(line[j])) {
            ++j;
        }
        prefixes.push_back(line.substr(cur_pos, j - (cur_pos)));
        return j;
    }
    
    int parseAttribute(string& line, int cur_pos) 
    {
        int first_quotes = line.find_first_of('"', cur_pos);
        int second_quotes = line.find_first_of('"', first_quotes + 1);
        
        auto kv = getKeyValuePair(line.substr(cur_pos, second_quotes + 1 - cur_pos));
        string prefix;
        for (string& p : prefixes) {
            prefix += p + "."; 
        }
        prefix.pop_back();
        dict.insert({prefix + "~" + kv.first, kv.second});
        return second_quotes;
    }
    
    string get(const string& query) {
        return dict.find(query) != dict.end()
            ? dict[query]
            : "Not Found!";
    }
    
    void removePrefix() {
        if (prefixes.size() > 0) {
            prefixes.pop_back();
        }
    }
};


void parseLine(Parser&p, string& line)
{
    for(size_t i = 0; i < line.size(); ++i) {
        if (line[i] == '<') {
            if (line[i + 1] == '/') {
                p.removePrefix();
                break;
            }
            else {
                i = p.parseTag(line, i + 1);
                continue;
            }
        }
        
        if (isalpha(line[i])) {
            i = p.parseAttribute(line, i);
            continue;
        }
    }
}

void readLines(Parser& p, int lines) {
    string line;
    while (lines-- != 0) {
        getline(cin, line, '\n');
        
        if (line.size() == 0) {
            continue;  
        } 
        
        parseLine(p, line);
    }
}

void readQueries(Parser& p, int queries) 
{
    string query;
    while (queries-- != 0) {
        getline(cin, query, '\n');
        cout << p.get(query) << '\n';
    }
}

int main() {
    string line;
    getline(cin, line, '\n');
    
    int space_idx = line.find_first_of(' ');
    int lines = stoi(line.substr(0, space_idx));
    int queries = stoi(line.substr(space_idx + 1));
    
    Parser p = Parser();
    
    readLines(p, lines);
    readQueries(p, queries);
    
    return 0;
}