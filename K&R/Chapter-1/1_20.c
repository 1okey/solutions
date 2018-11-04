#include <stdio.h>
#define identation 4

int main(){
    char c;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            c = ' ';
            printf("%*c",identation, c);
        } else 
            printf("%c",c);
    }
}