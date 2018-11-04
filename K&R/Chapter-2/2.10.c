#include <stdio.h>
#include <stdlib.h>

char lower(char c);

char lower(char c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}