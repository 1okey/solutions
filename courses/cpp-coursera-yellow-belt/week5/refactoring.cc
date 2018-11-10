#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string & name, const string& occupation)
        : name(name), occupation(occupation)
    {}
    virtual void Walk(const string & destination) const {
        cout << occupation << " walks to: " << destination << endl;
    }
    const string& get_name() const { return name; }
    const string& get_occupation() const { return occupation; }
protected:
    const string name;
    const string occupation;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
        : Person(name, "Student"), favourite_song(favouriteSong)
    {}

    void Learn() const {
        cout << "Student: " << name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << name << " walks to: " << destination << endl;
        cout << "Student: " << name << " sings a song: " << favourite_song << endl;
    }

    void SingSong() const {
        cout << "Student: " << name << " sings a song: " << favourite_song << endl;
    }

private:
    string favourite_song;
};

class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject)
        : Person(name, "Teacher"), subject(subject)
    {}

    void Teach() const {
        cout << "Teacher: " << name << " teaches: " << subject << endl;
    }
private:
    string subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
        : Person(name, "Policeman")
    {}

    void Check(const Person & p) const {
        cout << "Policeman: " << name << " checks " << p.get_occupation() << ". "
             << p.get_occupation() << "'s name is: " << p.get_name() << endl;
    }
};

void VisitPlaces(Person& h, const vector<string>& places) {
    for (auto p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
