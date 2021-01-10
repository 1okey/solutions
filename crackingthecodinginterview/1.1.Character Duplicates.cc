#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool checkCharacterDuplicates(const string& line){
    unordered_map<char,int> dict;

    for(char c: line) {
        if (c == ' ') continue;
        
        if (dict[c] > 0) {
            return false;
        }
    }

    return true;
}

int main() 
{
    string line = "poeairjva[lsdmvpojq[eoibnvl";
    cout << line << ' ' << checkCharacterDuplicates(line) << '\n';

    line = "This sentence contains a lot of letter T";
    cout << line << ' ' << checkCharacterDuplicates(line) << '\n';
    
    line = "Lazy";
    cout << line << ' ' << checkCharacterDuplicates(line) << '\n';

    line = "unique";
    cout << line << ' ' << checkCharacterDuplicates(line) << '\n';

    line = "qwe asd zxc tyu fgh vbn";
    cout << line << ' ' << checkCharacterDuplicates(line) << '\n';
}