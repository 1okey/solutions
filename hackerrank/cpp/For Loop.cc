// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

#include <string>

using namespace std;

const std::string num_map[9]= {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

int main()
{
    int from, to;
    cin >> from >> to;

    for (; from <= to; ++from) {
        cout << ( n <= 9 ? num_map[n - 1] : "Greater than 9" ) << endl;
    }

    return 0;
}
