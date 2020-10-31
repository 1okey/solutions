// https://www.hackerrank.com/challenges/c-tutorial-class/problem

#include <iostream>
#include <sstream>

using namespace std;

class Student {
private:
    int _age;
    int _standard;
    string _first_name;
    string _last_name;
public:
    void set_age(int age) { _age = age; }
    void set_first_name(const string & f_name) { _first_name = f_name; }
    void set_last_name(const string & l_name) { _last_name = l_name; }
    void set_standard(int standard) { _standard = standard; }
    int get_age() { return _age; }
    int get_standard() {  return _standard; }
    const string& get_first_name() { return _first_name; }
    const string& get_last_name() { return _last_name; }

    string to_string() {
        stringstream ss;
        ss << _age << ',' << _first_name << ',' << _last_name << ',' << _standard;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
