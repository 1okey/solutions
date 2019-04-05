// Implement strStr().

// Return the index of the first occurrence of needle in haystack, 
// or -1 if needle is not part of haystack.

int strStr(char* haystack, char* needle) {
    if(!*haystack && !*needle)
        return 0;
    
    for (unsigned i = 0; haystack[i]; ++i) {
        unsigned k = 0;
        for(; haystack[i + k] && needle[k]; ++k) {
            if(haystack[i + k] != needle[k])
                break;
        }
        
        if(needle[k] == '\0') {
            return i; 
        }
    }
    return -1;
}