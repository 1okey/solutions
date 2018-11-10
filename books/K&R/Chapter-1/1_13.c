#include <stdio.h>
#include <stdlib.h>

char* write_word(){
    char *string = (char*) malloc(8 * sizeof(char));
    char s;
    int length = 0;
    while((s = getchar()) != '\n' && ++length)
        *(string++) = s;
    *string = '\0';
    string -= length;
    return string;
}

int main (){
    int length = 5;
    char* words[5];
    for(int i = 0; i < length; i++){
        words[i] = write_word();
    }

    for(int i = 0; i < length; i++){
        char *p = words[i];
        while(*(p++)) printf("--");
        printf(" <-- ");
        p = words[i];
        while(*p) printf("%c", *(p++));
        printf("%c",'\n');
    }

    return 0;
}