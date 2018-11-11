#include "test_runner.h"

#include <algorithm>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
    if (free.empty()) {
      free.push(new T);
    }
    auto ret = free.front();
    free.pop();
    allocated.insert(ret);
    return ret;
  }

  T* TryAllocate(){
    if (free.empty()) {
      return nullptr;
    }
    return Allocate();
  }

  void Deallocate(T* object) {
    if (allocated.find(object) == allocated.end()) {
      throw invalid_argument("");
    }
    allocated.erase(object);
    free.push(object);
  }

  ~ObjectPool(){
    for (auto x : allocated) {
      delete x;
    }
    while (!free.empty()) {
      auto x = free.front();
      free.pop();
      delete x;
    }
  }

private:
  queue<T*> free;
  set<T*> allocated;
};

