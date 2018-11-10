#include <stdio.h>

int c_getline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 ; ++i)
    {
        if((c = getchar()) == EOF) break;
        if(c == '\n') break;
        else
        {
        s[i] = c;

        }
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


int main ()
{

}