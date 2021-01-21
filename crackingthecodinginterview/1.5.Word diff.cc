#include <string>
#include <iostream>
#include <unordered_map>

using std::string;
using std::cout;
using std::unordered_map;

bool are_word_one_change_away(const string& lhs, const string& rhs)
{
    unordered_map<char, int> dict;

    for(char c: lhs){
        dict[c]++;
    }

    for(char c: rhs){
        dict[c]--;
        if (dict[c] == 0) {
            dict.erase(c);
        }
    }

    return dict.size() <= 2;
}

int main()
{
    cout << (are_word_one_change_away("pale", "bale") ? "Yes" : "No") << '\n';

    cout << (are_word_one_change_away("pal", "pale") ? "Yes" : "No") << '\n';

    cout << (are_word_one_change_away("ple", "pale") ? "Yes" : "No") << '\n';

    cout << (are_word_one_change_away("pate", "patel") ? "Yes" : "No") << '\n';

    cout << (are_word_one_change_away("pate", "batel") ? "Yes" : "No") << '\n';

    cout << (are_word_one_change_away("bal", "pale") ? "Yes" : "No") << '\n';

    return 0;
}