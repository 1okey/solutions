#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

bool isAnagram(const string& original, const string& anagram){
    unordered_map<char,int> dict;

    for(char c: original) {
        char lower = c | 0x27;
        if (lower == ' ') {
            continue;
        }
        dict[lower]++;
    }

    for(char c: anagram) {
        char lower = c | 0x27;

        dict[lower]--;
        if (dict.find(lower) == dict.end()) {
            return false;
        }
        if(dict[lower] == 0) {
            dict.erase(lower);
        }
    }

    return dict.size() == 0;
}

int main() 
{
    vector<pair<string, string>> test_cases;
    
    test_cases.emplace_back(make_pair("rat", "tar"));
    test_cases.emplace_back(make_pair("bored", "robed"));
    test_cases.emplace_back(make_pair("Bored", "Robed"));
    test_cases.emplace_back(make_pair("true", "false"));

    for (auto test: test_cases) {
        cout << test.first << ' ' <<  test.second << ' ' << isAnagram(test.first, test.second) << '\n';
    }

    return 0;
}