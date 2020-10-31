// https://www.hackerrank.com/challenges/c-tutorial-struct/problem

#include <iostream>

using namespace std;

struct Student {
    int age;
    string last_name;
    string first_name;
    int standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
