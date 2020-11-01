// Given a string s consists of upper/lower-case alphabets and empty space 
// characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.
#include <ctype.h>

int lengthOfLastWord(char* s) {
    unsigned i = 0;
    while (*s) {
        if (isalpha(*s))
            i = 0;
        
        while (isalpha(*s)) {
            ++s;
            ++i;
        }
        
        if(!*s) 
            break;
        
        ++s;
    }
    return i;
}