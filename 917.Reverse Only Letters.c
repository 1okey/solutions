bool isChar(char c){
    return ((65 <= c && c <= 90) ||
            (97 <= c && c <= 122));
}

char* reverseOnlyLetters(char* s) {
    unsigned end = strlen(s) - 1;
    unsigned start = 0;
    
    if(end == -1 || end == start) return s;
    
    for(; start <= end;){
        if(!isChar(s[start])){
            ++start;
            continue;
        }
        if(!isChar(s[end])){
            --end;
            continue;
        }

        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        ++start; --end;
    }
    return s;
}
