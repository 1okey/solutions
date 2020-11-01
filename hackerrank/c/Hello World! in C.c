// https://www.hackerrank.com/challenges/for-loop-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const char* num_map[9]= {
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
    int a, b;
    scanf("%d\n%d", &a, &b);

    for (; a <= b; ++a) {
        if (a <= 9) {
            printf("%s\n", num_map[a - 1]);
        } else {
            printf("%s\n", a % 2 == 1 ? "odd" : "even");
        }
    }

    return 0;
}
