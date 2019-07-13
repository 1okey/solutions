#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x){
    
    if (x < 0) return false;
    if (x == 0) return true;

    // setting up left and right divisor and modulus
    const unsigned max = 1000000000;
    unsigned right_div = 1;
    unsigned right_mod = 10;
    unsigned left_mod = max;
    
    // getting significant leftmost part of number
    while (x / (left_mod / 10) == 0) left_mod /= 10;
    
    // in case if mod == div (need a better solution)
    bool is_max = left_mod == max;
    unsigned left_div = is_max ? left_mod : left_mod / 10;

    // variables to store number values
    unsigned short left = 0, right = 0;
    
    while(left_div > right_div) {
        
        left = is_max ? x / left_div : ((x % left_mod) / left_div);
        right = (x % right_mod) / right_div;
        is_max = false;
        
        if (left != right) {
            return false;
        }

        left_mod = left_div;
        right_div = right_mod;
        right_mod *= 10;
        left_div /= 10;
    }

    return true;
}

void TestIsPalindrome(int x) {
    printf("%s\n", isPalindrome(x) ? "true" : "false");
}

int main(){
    TestIsPalindrome(121);
    TestIsPalindrome(1221);
    TestIsPalindrome(12321);
    TestIsPalindrome(123321);
    TestIsPalindrome(1234321);
    TestIsPalindrome(-121);
    TestIsPalindrome(1000000001);
    TestIsPalindrome(-1000000001);
}

