int binaryGap(int N) {
    // removing leading zeros
    while (!(N & 0x1)) N>>= 1;

    // removing even numbers;
    if(!(N & (N -1)))
      return 0;

    int i = 0, n = 0, max = 0;
    while(N){
        n = N & 0x1 ? 0 : n + 1;
        if(n >= max)
            max = n;
        N >>= 1;
    }
    return (max + 1);
}
