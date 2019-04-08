#include <stdbool.h>

// We define the Perfect Number is a positive integer that is equal to the 
// sum of all its positive divisors except itself.

// Now, given an integer n, write a function that returns true when it is
//  a perfect number and false when it is not.
// Example:
// Input: 28
// Output: True
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// Note: The input number n will not exceed 100,000,000. (1e8)

bool checkPerfectNumber(int num) {
    if (num <= 1)
        return false;
    
    int high = num / 2;
    int low = 2;
    int acc = 1;
    while(low < high) {
        if(num % low == 0) {
            acc += low;
            high = num / low;
            acc += high;
        }
        ++low;
    }
    return acc == num;
}