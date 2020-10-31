// https://www.hackerrank.com/challenges/rectangle-area/problem

#include <iostream>

using namespace std;

struct Rectangle {
    int h,w;
    void display() {
        cout << h << ' ' << w << '\n';
    }
};

struct RectangleArea: public Rectangle {
    void read_input() {
        cin >> h >> w;
    }

    void display() {
        cout << (h * w); 
    }
};

