#define EOF 0
#include <stdio.h>

void escape(){
    char c;
    while((c = getchar()) != EOF){
        switch(c){
            case '\t':
                putchar('\\t');
                break;
            case '\n':
                putchar('\\n');
                break;
            default: putchar(c);
        }
    }
}

int main(){
    escape();
    return 0;
}