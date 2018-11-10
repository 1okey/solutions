#include <stdio.h>

int main(){
    char c;
    int t_cnt = 0, s_cnt = 0, b_cnt = 0;
    while((c = getchar()) != EOF){
        if(c == '\n') b_cnt++;
        if(c == ' ') s_cnt++;
        if(c == '\t') t_cnt++;
    }
    printf("spaces: %d\ntabs: %d\nbreaks: %d", s_cnt, t_cnt, b_cnt);
    return 0;
}