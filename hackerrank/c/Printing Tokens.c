// https://www.hackerrank.com/challenges/printing-tokens-/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    
    unsigned len = strlen(s) + 1;
    s = realloc(s, len);
    
    for (unsigned i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            s[i] = '\n';
        }
    }
    
    printf("%s", s);
    return 0;
}