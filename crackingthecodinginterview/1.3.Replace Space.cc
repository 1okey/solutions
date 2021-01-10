#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

string replacesSpaces(const string& sentence){
    vector<char> output;
    output.reserve(sentence.size());

    for (char c: sentence) {
        if (c == ' ') {
            output.push_back('%');
            output.push_back('2');
            output.push_back('0');
        } else {
            output.push_back(c);
        }
    }

    return string(output.begin(), output.end());
}

int main() 
{
    vector<string> test_cases = {
        "This string has 3 spaces",
        "This one has 4 spaces, indeed",
    };

    for (auto test: test_cases) {
        cout << test << " ---> " << replacesSpaces(test) << '\n';
    }

    return 0;
}