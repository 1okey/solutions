#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

// Дано целое положительное число N, не превышающее 9. Выведите все перестановки
// чисел от 1 до N в обратном лексикографическом порядке (см. пример).

int main(){
  int n;
  cin >> n;
  vector<int> mutations(n);
  int j = n;
  for(auto& i : mutations){
    i = j--;
  }

  do{
    for(auto& i : mutations){
      cout << i << " ";
    }
    cout << endl;
  } while(prev_permutation(mutations.begin(),mutations.end()));
}

