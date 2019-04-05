// Count the number of prime numbers less than a non-negative number, n.

#include <math.h>

int isPrime(int num) {
    int lim = sqrt(num);
    for (unsigned i = 2; i <= lim; ++i) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int countPrimes(int n) {
    if (n <= 2)
        return 0;
    
    int count = 1;
    int num = 3;
    
    while (num < n) {
        if (isPrime(num))
            ++count;
        ++num;
    }
    
    return count;
}