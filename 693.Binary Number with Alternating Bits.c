bool hasAlternatingBits(int n) {
    int bit = n & 0x1;
    while(n != 0){
        n >>= 1;
        if((n & 0x1) == bit) return false;
        bit = n & 0x1;
    }
    return true;
}
