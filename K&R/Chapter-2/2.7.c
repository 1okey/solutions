#include <stdio.h>

unsigned invert(unsigned x, int pos, int num);

int main()
{
    printf("%d", invert(12,1,2));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}
