#include <stdio.h>

int main(){
    char c;
    int t_cnt = 0, s_cnt = 0, b_cnt = 0;
    while((c = getchar()) != EOF){
        if(c == '\n') printf("\\n");
        else if(c == '\\') printf("\\");
        else if(c == '\t') printf("\\t");
        else putchar(c);   
    }
    return 0;
}