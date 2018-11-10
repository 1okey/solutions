#include <string>
#include <vector>
using namespace std;

#define GET_NAME(line) local_var##line
#define GET_LINE(line) GET_NAME(line)
#define UNIQ_ID GET_LINE(__LINE__)

int main(){
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}

