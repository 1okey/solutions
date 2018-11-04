#include <stdio.h>
#define OUT  0
#define IN  1

int main() {

    int c, state, i = 0;
    state = OUT;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            putchar('\n');
        } else if(state == IN)
            putchar(c);
        else if(state == OUT)
        {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}