#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

string compressString(const string& str){
    vector<char> output;

    for(int i = 0; i < str.size(); ++i) {
        int j = i;

        while(j < str.size() && str[i] == str[j]) {
            ++j;
        }

        output.push_back(str[i]);
        output.push_back((j - i) + '0');
        i = j - 1; 
    }

    bool all_single = true;
    for (int i = 1; i < output.size(); i += 2) {
        if (output[i] - '0' > 1) {
            all_single = false;
            break;
        }
    }

    return all_single ? str : string(output.begin(), output.end());
}

int main() 
{
    vector<string> test_cases = {
        "aaaabbbrrrracaaaadaaaaabrrrrrraa",
        "abracadabra",
    };

    for (auto test: test_cases) {
        cout << test << " ---> " << compressString(test) << '\n';
    }

    return 0;
}