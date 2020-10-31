// https://www.hackerrank.com/challenges/c-tutorial-strings/problem

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
	cin >> a >> b;
    cout << a.size() << ' ' << b.size() << '\n'
         << a + b << '\n'
         << (b[0] + a.substr(1)) << ' '
         << (a[0] + b.substr(1))
         << endl;

    return 0;
}
