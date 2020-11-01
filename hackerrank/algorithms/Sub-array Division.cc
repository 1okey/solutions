// https://www.hackerrank.com/challenges/the-birthday-bar/problem

using namespace std;

int birthday(vector<int> s, int d, int m) {
    int count = 0;
    for(auto it = s.begin(); it != s.end(); ++it) 
    {
        count += d == accumulate(it, it + m, 0);
    }
    return count;
}

