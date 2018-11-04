#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;

void squeeze(char * s1, int s1l, char * s2, int s2l);

int main()
{
    char s1[7] = "string1";
    char s2[7] = "bfreng2";
    squeeze(s1, 7, s2, 7);
    return 0;
}

void squeeze(char * s1, int s1l, char * s2, int s2l)
{
    int i,j,k = 0;
    bool skip;
    for(i = 0; i < s1l; i++){
        skip = false;
        for(j = 0; j < s2l; j++){
            if(s2[j] == s1[i])
            {
                skip = true;
                break;                    
            }
        }

        if(!skip){
            s1[k++] = s1[i];
        }
    }
    s1[k] = 0;
    printf("%s - %lu", s1, strlen(s1));
}


