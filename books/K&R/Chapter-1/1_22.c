#include <stdio.h>
#define identation 4
#define TAB 0x09
#define END "|LINE END\n"

void ruler(int limit){
    char c; int counter = 0;
    while((c = getchar()) != EOF){
        counter++;
        if(c == '\n'){
            printf("%*c%s",(limit - counter), ' ', END);
            counter = 0;
        }
        if(c == '\t') counter += 3;
        if(counter == limit) {
            counter = 0;
            printf("%s%c", END, c);
        } else {
            printf("%c",c);
        }
    }
}

int main(){
    ruler(80);
    return 0;
}