// https://www.hackerrank.com/challenges/frequency-of-digits-1/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char* line = (char*) malloc(1024 * sizeof(char));
    int freqs[10]= {0};
    scanf("%s", line);
    unsigned len = strlen(line);
    
    for (unsigned i = 0; i < len; ++i) {
        if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
            freqs[line[i] - '0']++;
        }
    }
    
    for (unsigned i = 0; i <= 9; ++i) {
        printf("%d ", freqs[i]);
    }

    return 0;
}
