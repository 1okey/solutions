#include <stdio.h>
#define MAXLINE 1000

int c_getline(char line[], int maxline);

int main()
{
    int len, min = 80;
    char line[MAXLINE];
    char longest[MAXLINE];
    while((len = c_getline(line, MAXLINE)) > 0)
        if (len > min)
            printf("%s", line);
    return 0;
}

int c_getline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}