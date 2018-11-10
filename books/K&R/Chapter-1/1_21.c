#include <stdio.h>
#define identation 4
#define TAB 0x09

int main(){
    char c; int idnt_counter = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            ++idnt_counter;
            if(idnt_counter == identation)
                printf("%c", TAB);
        } else {
            idnt_counter = 0;
            printf("%c",c);
        }
    }
}