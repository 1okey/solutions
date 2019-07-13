static int asyncx = [](){
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 std::cout.tie(nullptr);
 return 0;
}();

class Solution {
public:
  bool rotateString(string A, string B) {

    size_t i = 0;
    while(i < A.size()){
      if(A == B) return true;
      A = A.substr(1) + A.front();
      ++i;
    }
    return A == B;
  }
};

