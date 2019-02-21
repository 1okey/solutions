bool isAnagram(char* s, char* t) {
    int * count = (int*) calloc(26, sizeof(int));
    while(*s != 0 && *t != 0){
        count[((*s++) - 'a')]++;
        count[((*t++ )- 'a')]--;
    }
    
    if(*s != 0 || *t != 0) return false;
    
    for(unsigned i = 0; i < 26; ++i)
        if (count[i] != 0)
            return false;
    
    free(count);
    return true;
}
