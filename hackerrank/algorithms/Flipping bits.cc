// https://www.hackerrank.com/challenges/flipping-bits/problem

long flippingBits(long n) {
    long flipped = 4294967295; // max 32 bit value

    return n ^ flipped;
}
