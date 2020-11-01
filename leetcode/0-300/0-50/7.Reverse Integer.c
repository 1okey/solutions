#include <stdio.h>
#include <limits.h>

int reverse(int x){
    
    if(x == 0 || x > INT_MAX || x < INT_MIN) return 0;

    int div = 1;
    int mod = 10;
    int mul = 1000000000;
    
    while (x / mul == 0) mul /= 10;
    
    int result = 0;
    
    while(x / div != 0) {
        result += (x % mod / div) * mul;
        mul /= 10;
        div = mod;
        mod *= 10;
    }

    return result;
}

void TestReverseInteger(){
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(1));
    printf("%d\n", reverse(-1));
    printf("%d\n", reverse(0));
}

int main (){
    TestReverseInteger();
    return 0;
}
