// https://www.hackerrank.com/challenges/printing-pattern-2/problem 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() 
{

    int n, num;
    scanf("%d", &n);
    unsigned max = n * 2 - 1;
  	for(unsigned i = 0; i < max; ++i){
        for(unsigned j = 0; j < max; ++j){
            int m = min(i, j);
            m = min(m, max - i - 1);
            m = min(m, max - j - 1);
            printf("%d ", n - m);
        }
        printf("\n");
    }
    return 0;
}