#include <stdio.h>
#define true 1
#define false 0
typedef int bool;

bool is_delimiter(char ch)
{
    return ch == ' ' || ch == '\t';
}

int main()
{
    char ch;
    char line[1000] = "";
    int index = 0;
    bool added = false;
    while((ch = getchar()) != EOF)
    {
        if(ch == '\n') continue;
        if(is_delimiter(ch) && !added)
        {
            added = true;
            line[index++] = ch;
        }
        else if(!is_delimiter(ch))
        {
            line[index++] = ch;
            added = false;
        }
    }
    printf("%s", line);
    return 0;
}