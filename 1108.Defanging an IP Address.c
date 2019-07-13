#include <stdlib.h>
#include <stdio.h>

char * defangIPaddr(char * address){
    // 7 is [] times 3 + null termination sign    
    char * defanged = (char*) malloc(strlen(address) + 7);
    char * it = defanged;

    while(*address) {
        if(*address == '.') {
            *it++ = '[';
            *it++ = '.';
            *it++ = ']';
        } else {
            *it++ = *address;
        }
        ++address;
    }
    *it = 0;
    return defanged;
}

int main() {
    char s[] = "1.1.1.1";
    char s1[] = "192.168.0.1";
    char s2[] = "255.255.255.255";
    char * result = defangIPaddr(s);
    char * result1 = defangIPaddr(s1);
    char * result2 = defangIPaddr(s2);
    
    printf("%s\n", result);
    printf("%s\n", result1);
    printf("%s\n", result2);

    return 0;
}