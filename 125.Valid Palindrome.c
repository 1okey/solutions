#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(char* s) {
    int len = strlen(s);
    
    if(len <= 1)
        return true;
    
    int tail = len - 1;
    
    for (int head = 0; head <= tail; ++head, --tail) {
        
        while (!isalnum(s[head]) && head < len) 
            ++head;

        while (!isalnum(s[tail]) && tail > 0) 
            --tail;

        if (head > tail)
            break;
        
        if (tolower(s[head]) != tolower(s[tail])) 
            return false;

    }
    
    return true;
}

int main() {
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";
    char s3[] = "a.";
    char s4[] = ".,";
    char s5[] = "0P";

    printf("%d\n", isPalindrome(s1));
    printf("%d\n", isPalindrome(s2));
    printf("%d\n", isPalindrome(s3));
    printf("%d\n", isPalindrome(s4));
    printf("%d\n", isPalindrome(s5));
}