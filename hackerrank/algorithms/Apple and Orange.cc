// https://www.hackerrank.com/challenges/apple-and-orange/problem

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int _apples = 0, _oranges = 0;
    for (int & _a : apples)   _apples += (_a + a) >= s && (_a + a) <= t;
    for (int & _o : oranges) _oranges += (_o + b) >= s && (_o + b) <= t;
    cout << _apples << '\n' << _oranges;
}