// https://www.hackerrank.com/challenges/preprocessor-solution/problem

#include <limits>

#define toStr(str) #str
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)
#define io(v) cin>>v
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define INF 2147483647

