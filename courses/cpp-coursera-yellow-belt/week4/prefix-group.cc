#include <utility>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
  return pair<RandomIt, RandomIt>{
    lower_bound(range_begin,range_end, string(1,prefix)),
    lower_bound(range_begin,range_end, string(1,static_cast<char>(prefix + 1)))
  };
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string prefix){
  string upper_bound = prefix;
  ++(upper_bound[upper_bound.size() -1 ]);
  return pair<RandomIt, RandomIt>{
    lower_bound(range_begin,range_end, prefix),
    lower_bound(range_begin,range_end, upper_bound)
  };
}

