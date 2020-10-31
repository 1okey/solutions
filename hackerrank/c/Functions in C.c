// https://www.hackerrank.com/challenges/functions-in-c/problem

#include <stdio.h>
#include <math.h>

int max(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

int max_of_four(int a, int b, int c, int d)
{
    return max(max(a,b), max(c,d));
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
