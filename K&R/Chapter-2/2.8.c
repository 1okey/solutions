#include <stdio.h>

unsigned rightroot(unsigned x, int num);

int main()
{
    printf("%d", rightroot(12,1));
    return 0;
}

unsigned int rightrot(unsigned x, int n)
{
    int y = wordlength();
    int rbit; //rightmost bit

    while (n-- > 0){
        rbit = (x & 1) << (y - 1); //takes the rightmost bit of x and shifts it to the leftmost position (wordlength() - 1)
        x = x >> 1;   //shift x one position to the right
        x = x | rbit; //complete one rotation
    }
    return x;
}