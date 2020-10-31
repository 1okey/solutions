// https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

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
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << ( n <= 9 ? num_map[n - 1] : "Greater than 9" ) << endl;

    return 0;
}
