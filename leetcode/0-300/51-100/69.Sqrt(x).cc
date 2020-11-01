#include <cmath>

static int asyncx = [](){
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 return 0;
}();

class Solution {
public:
    int mySqrt(int x) {
      if (x == 1) 
          return 1;
      double ubound = x;
      double lbound = 0;
      double n = 0;
      while(fabs(x - (n * n)) > 0.01){
        n = (lbound + ubound) / 2.0;
        if(n * n >= x){
          ubound = n;
        } else {
          lbound = n;
        }
      }
      return n;
    }
};
