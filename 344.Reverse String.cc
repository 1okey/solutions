reverseString(char* s, int sSize) {
    if(!sSize) return;
        
    for(unsigned i = 0, j = sSize - 1;
        i <= sSize / 2 && i <= j;
        ++i, --j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
