// https://www.hackerrank.com/challenges/staircase/problem

void staircase(int n) {
    for (int i = 1; i <= n; ++i)
    {
        cout << setw(n) << string(i, '#') << '\n';
    }
}
