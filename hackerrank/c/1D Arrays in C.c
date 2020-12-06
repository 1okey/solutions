// https://www.hackerrank.com/challenges/1d-arrays-in-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned size;
    scanf("%d", &size);
    
    int n;
    int sum = 0;
    for(unsigned i = 0; i < size; ++i) {
        scanf("%d", &n);
        sum += n;
    }
    
    printf("%d", sum);
    
    return 0;
}