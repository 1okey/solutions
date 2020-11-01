static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
   // bool isBitPrime(int n){
   //     int b = 0;
   //     while(n){
   //         b += (n & 0x1);
   //         n >>= 1;
   //     }

   //     return b == 2 || b == 3 || b == 5 || b == 7 || b == 11 || b == 13 || b == 17 || b == 19 ||
   //            b == 23 || b == 29 || b == 31;
   //}

    bool isBitPrime(int n){
        int b_count = 0;
        int n_cpy = n;
        while(n_cpy){
            b_count += (n_cpy & 0x1);
            n_cpy >>= 1;
        }
        for(unsigned d = 2; d <= b_count / 2; ++d){
            if(b_count % d == 0) return false;
        }
        return b_count != 1;
    }

    int countPrimeSetBits(int L, int R) {
        int n_count = 0;
        for(; L <= R; ++L){
            if(isBitPrime(L)) ++n_count;
        }
        return n_count;
    }
};
