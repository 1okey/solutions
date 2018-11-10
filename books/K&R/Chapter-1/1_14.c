#include <stdio.h>

int cnt[30] = {0};
char table[30] = {};

int find_char(char ch){
    int index = -1;
    for(int i = 0; table[i]; i++)
        if(table[i] == ch)
            index = i;
    return index;
}

int main(){
    char c;
    int index = 0, last = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t') continue;
        if((index = find_char(c)) > -1)
            cnt[index]++;
        else{
            table[last] = c;
            cnt[last] = 1;
            last++;
        }
    }

    for(int i = 0; table[i]; i++){
        printf("%c", table[i]);
        int ammount = cnt[i];
        for(int j = 0; j < ammount; j++)
            printf("-");
        printf("\n");
    }
    return 0;
}