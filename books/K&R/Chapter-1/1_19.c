#include <stdio.h>
#define MAXLINE 1000

int c_getline(char line[]);
void c_copy(char to[], char from[], int len);

int main()
{
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    while((len = c_getline(line)) > 0)
    {
        c_copy(longest, line, len - 1);
    }
    printf("%s", longest);
    return 0;
}

int c_getline(char s[])
{
    int c, i;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

void c_copy(char to[], char from[], int len)
{
    int i = len, j = 0;
    while ((to[j++] = from[i--]) != '\0') continue;
}