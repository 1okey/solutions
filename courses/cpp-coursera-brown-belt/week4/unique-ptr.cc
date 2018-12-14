#include "test_runner.h"

#include <cstddef>
#include <algorithm>

using namespace std;

template <typename T>
class UniquePtr {
private:
  UniquePtr(const UniquePtr& ptr) = delete;
  UniquePtr& operator = (const UniquePtr& ptr) = delete;
  T* resource = nullptr;
public:
  UniquePtr() = default;
  UniquePtr(T * ptr): resource(ptr){}
  UniquePtr(UniquePtr&& other) {
    resource = other.Release();
  }

  UniquePtr& operator = (nullptr_t){
    delete resource;
    resource = nullptr;
    return *this;
  }

  UniquePtr& operator = (UniquePtr&& other){
    resource = other.Release();
    return *this;
  }

  ~UniquePtr(){
    delete resource;
  }

  T& operator * () {
    return *resource;
  }

  T& operator * () const {
    return *resource;
  }

  T * operator -> () const {
    return resource;
  }

  T * Release(){
    T* tmp = resource;
    resource = nullptr;
    return tmp;
  }

  void Reset(T * ptr){
    delete resource;
    resource = ptr;
  }

  void Swap(UniquePtr& other){
    T* tmp = resource;
    resource = other.Release();
    other.Reset(tmp);
  }

  T * Get() const{
    return resource;
  }
};


struct Item {
  static int counter;
  int value;
  Item(int v = 0): value(v) {
    ++counter;
  }
  Item(const Item& other): value(other.value) {
    ++counter;
  }
  ~Item() {
    --counter;
  }
};

int Item::counter = 0;


void TestLifetime() {
  Item::counter = 0;
  {
    UniquePtr<Item> ptr(new Item);
    ASSERT_EQUAL(Item::counter, 1);

    ptr.Reset(new Item);
    ASSERT_EQUAL(Item::counter, 1);
  }
  ASSERT_EQUAL(Item::counter, 0);

  {
    UniquePtr<Item> ptr(new Item);
    ASSERT_EQUAL(Item::counter, 1);

    auto rawPtr = ptr.Release();
    ASSERT_EQUAL(Item::counter, 1);

    delete rawPtr;
    ASSERT_EQUAL(Item::counter, 0);
  }
  ASSERT_EQUAL(Item::counter, 0);
}

void TestGetters() {
  UniquePtr<Item> ptr(new Item(42));
  ASSERT_EQUAL(ptr.Get()->value, 42);
  ASSERT_EQUAL((*ptr).value, 42);
  ASSERT_EQUAL(ptr->value, 42);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLifetime);
  RUN_TEST(tr, TestGetters);
}

