#include <stdio.h>
#define MAXLINE 1000

int c_getline(char line[]);
void c_copy(char to[], char from[]);

int main()
{
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    while((len = c_getline(line)) > 0)
    {
        if (len > max)
        {
            max = len;
            c_copy(longest, line);
        }
    }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

int c_getline(char s[])
{
    int c, i;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void c_copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}