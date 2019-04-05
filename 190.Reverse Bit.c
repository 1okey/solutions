#include <stdint.h>

// Reverse bits of a given 32 bits unsigned integer.

uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;
    int shift = 31;
    while (n > 0) {
        r |= ((n & 0x1) << shift);
        n >>= 1;
        shift--;
    }
    return r;
}