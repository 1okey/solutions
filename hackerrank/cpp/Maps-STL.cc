// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <iostream>
#include <map>

using namespace std;

int main() {
    int q, q_type;
    cin >> q;
    map<string,int> students;
    string name;
    int mark;
    while(q != 0) {
        cin >> q_type;
        switch(q_type) {
            case 1: 
                cin >> name >> mark;
                students[name] += mark;
                break;
            case 2: 
                cin >> name;
                students.erase(name);
                break;
            case 3: 
                cin >> name;
                int mark = students.find(name) == students.end() ? 0 : students.at(name);
                cout << mark << '\n';
                break;
        }
        --q;
    }
    return 0;
}



