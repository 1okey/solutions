#include <string>
#include <iostream>

using std::string;
using std::cout;

string is_palindrome_permutation_one(const string& input) // time - O(n), space - O(n)
{
    int dict[26] = {0};

    for (char c : input) { // O(n)
        if (c == ' ') continue;

        dict[(char)c - 0x61]++;
    }

    bool is_palindrome = false;
    for(unsigned i = 0; i < 26; ++i) { // O(26) ~ O(1)
        if (dict[i] % 2 == 1) {
            if (is_palindrome) {
                return "no";
            }
            is_palindrome = true;
        }
    }

    return "yes";
}

string is_palindrome_permutation_two(const string& input) // time - O(n)
{
    int dict[26] = {0};
    int odd_counter = 0;

    for (char c : input) { // O(n)
        if (c == ' ') continue;

        dict[(char)c - 0x61]++;
        
        odd_counter += dict[(char)c - 0x61] % 2 == 1 ? 1 : -1;
    }

    return odd_counter <= 1 ? "yes" : "no";
}

int main()
{
    string test_str = "abab cebeb";
    cout << is_palindrome_permutation_one(test_str) << '\n';
    
    test_str = "ababd cebeb";
    cout << is_palindrome_permutation_one(test_str) << '\n';

    test_str = "ababc cebeb";
    cout << is_palindrome_permutation_two(test_str) << '\n';

    test_str = "ababd cebeb";
    cout << is_palindrome_permutation_two(test_str) << '\n';

    return 0;
}