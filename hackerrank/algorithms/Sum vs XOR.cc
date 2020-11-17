// https://www.hackerrank.com/challenges/sum-vs-xor/problem

long sumXor(long n) {
    int zeroes = 0;
    
    while(n != 0) {
        // sum of numbers and their xor will be equal at positions where bit is equal to 0
        zeroes += n % 2 == 0;
        n >>=1;
    }
    
    return pow(2, zeroes);
}