// https://www.hackerrank.com/challenges/c-tutorial-functions/problem

#include <iostream>
#include <cstdio>

using namespace std;

int max_of_four(int a, int b, int c, int d)
{
    int lhs, rhs;
    
    lhs = a > b ? a : b;
    rhs = c > d ? c : d;
    
    return lhs > rhs ? lhs : rhs;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
