typedef int bool;
#define true 1
#define false 0

#include <stdio.h>

int main(){
    char c;
    bool flag;
    while((c = getchar()) != EOF){
        if(c == ' ') {
            if(flag == true ) continue;
            putchar(c);
            flag = true;
        } else {
            flag = false;
            putchar(c);
        }
    }
    return 0;
}