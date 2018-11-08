#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "test_runner.h"

using namespace std;

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);

int Sum(int x, int y){
  return x + y;
}

string Reverse(string s){
  string n_s;
  for(auto c : s){
    n_s.insert(0, 1, c);
  }
  return n_s;
}

void Sort(vector<int>& sums){
  sort(sums.begin(), sums.end());
}

void TestSum(){
  ASSERT_EQUAL(Sum(2,3),5);
  ASSERT_EQUAL(Sum(3,3),6);
  ASSERT_EQUAL(Sum(2,-3),-1);
  ASSERT_EQUAL(Sum(0,0),0);
}

void TestReverse(){
  ASSERT_EQUAL(Reverse("solomon"),"nomolos");
  ASSERT_EQUAL(Reverse("reverse"),"esrever");
  ASSERT_EQUAL(Reverse("equal"),"lauqe");
  ASSERT_EQUAL(Reverse("wrong"),"gnorw");
}

void TestSort(){
  {
    vector<int> source = {3,1,2};
    Sort(source);
    vector<int> expected = {1,2,3};
    ASSERT_EQUAL(source, expected);
  }
  {
    vector<int> source = {1,2,3};
    Sort(source);
    vector<int> expected = {1,2,3};
    ASSERT_EQUAL(source, expected);
  }
  {
    vector<int> source = {9,5,8,2,4,8};
    Sort(source);
    vector<int> expected = {2,4,5,8,8,9};
    ASSERT_EQUAL(source, expected);
  }
}

int main(){
  TestRunner tr;
  RUN_TEST(tr,TestSum);
  RUN_TEST(tr,TestReverse);
  RUN_TEST(tr,TestSort);
}

