// https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person() = default;
    virtual void getdata() {
        cin >> name >> age;
    }
    virtual void putdata() {
        cout << name << ' ' << age << ' ';
    }
};

class Professor: public Person {
private:
    int publication;
    int id;
public:
    static int _id;

    Professor()
    { 
        Professor::_id++;
        id = Professor::_id;
    }
    void getdata()  {
        Person::getdata();
        cin >> publication;
    }
    void putdata()  {
        Person::putdata();
        cout << publication << ' ' << id << '\n';
    }
};
int Professor::_id = 0;

class Student: public Person {
private:
    int id;
    vector<int> marks;
public:
    static int _id;
    static const int MARKS = 6;

    Student()
    { 
        Student::_id++;
        id = Student::_id;
    }
    void getdata()  {
        Person::getdata();
        int mark;
        int i = 0;
        while(i < Student::MARKS) {
            cin >> mark;
            marks.push_back(mark);
            ++i;
        }
    }
    void putdata()  {
        Person::putdata();
        int sum = 0;
        for(size_t i = 0; i < marks.size() && i < 6; ++i) {
            sum += marks[i];
        }
        cout << sum << ' ' << id << '\n';
    }
};

int Student::_id = 0;


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
