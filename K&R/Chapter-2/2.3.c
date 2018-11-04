#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    while((c = getchar()) != EOF)
    {
        if(isalnum(c) || isdigit(c)){
            printf("%d - %c\n", (int)c, c);
        }
    }
    
    return 0;
}