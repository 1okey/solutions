// https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int max(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    int and = 0, or = 0, xor = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((i & j) < k) and = max(and, i & j);
            if ((i | j) < k) or = max(or, i | j);
            if ((i ^ j) < k) xor = max(xor, i ^ j);
        }
    }
    printf("%d\n%d\n%d", and, or, xor); 
    return 0;
}
