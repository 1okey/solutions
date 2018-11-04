#include <stdio.h>

unsigned setbits(unsigned x, int pos, int num, unsigned y);


int main()
{
    printf("%d", getbits(5,0,3));
    return 0;
}


unsigned setbits(unsigned x, int pos, int num, unsigned y)
{
    return x & ~(~(~0 << pos) << (pos+1-num)) | ((y &  ~(~0 << num)) << (pos+1-num));
}
