#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;

int any(char * s1, int s1l, char * s2, int s2l);

int main()
{
    char s1[7] = "string1";
    char s2[7] = "o";
    int result = any(s1, 7, s2, 7);
    printf("%d", result);
    return 0;
}

int any(char * s1, int s1l, char * s2, int s2l)
{
    int i,j,k;
    bool skip;
    for(i = 0; i < s1l; i++){
        k = -1;
        for(j = 0; j < s2l; j++){
            if(s2[j] == s1[i])
                return i;
        }
    }
    return k;
}


