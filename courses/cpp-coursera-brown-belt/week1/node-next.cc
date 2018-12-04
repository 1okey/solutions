#include "test_runner.h"
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;

// В данной задаче мы будем работать не с контейнером set, но с аналогичным двоичным деревом
// поиска, состоящим из следующих вершин:
struct Node {
  Node(int v, Node* p)
    : value(v)
    , parent(p)
  {}

  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent;
};

// Где:
//
//  value - значение, хранящееся в вершине;
//  left и right - указатели на дочерние вершины (оба равны nullptr для листьев дерева);
//  parent - указатель на родительскую вершину (равен nullptr для корня дерева).
//  Допустим, что для обхода дерева мы используем не специальный итератор, а просто указатель на вершину Node*.
//
//  Вам требуется реализовать функцию ,возвращающую указатель на следующую по возрастанию значения
//  вершину:
//
Node* Next(Node* node);
//
//  Функция должна вернуть nullptr в случае, если текущая вершина -- последняя в дереве.

Node* Next(Node* node){
  if(node->right){
    node = node->right;
    while(node->left) node = node->left;
    return node;
  }

  if(node->parent && node->parent->left == node){
    return node->parent;
  }

  if(!node->right && node->parent && node->parent->right == node){
    while(node->parent && node != node->parent->left) node = node->parent;
    if(!node->parent) return nullptr;
    return node->parent;
  }

  return nullptr;
}

class NodeBuilder {
public:
  Node* CreateRoot(int value) {
    nodes.emplace_back(value, nullptr);
    return &nodes.back();
  }

  Node* CreateLeftSon(Node* me, int value) {
    assert( me->left == nullptr );
    nodes.emplace_back(value, me);
    me->left = &nodes.back();
    return me->left;
  }

  Node* CreateRightSon(Node* me, int value) {
    assert( me->right == nullptr );
    nodes.emplace_back(value, me);
    me->right = &nodes.back();
    return me->right;
  }

private:
  deque<Node> nodes;
};

void Test1() {
  NodeBuilder nb;

  Node* root = nb.CreateRoot(50);
  ASSERT_EQUAL( root->value, 50 );

  Node* l = nb.CreateLeftSon(root, 2);
  Node* min = nb.CreateLeftSon(l, 1);
  Node* r = nb.CreateRightSon(l, 4);
  ASSERT_EQUAL( min->value, 1);
  ASSERT_EQUAL( r->parent->value, 2 );

  nb.CreateLeftSon(r, 3);
  nb.CreateRightSon(r, 5);

  r = nb.CreateRightSon(root, 100);
  l = nb.CreateLeftSon(r, 90);
  Node* m = nb.CreateRightSon(r, 101);

  nb.CreateLeftSon(l, 89);
  r = nb.CreateRightSon(l, 91);

  ASSERT_EQUAL( Next(l)->value, 91);
  ASSERT_EQUAL( Next(root)->value, 89 );
  ASSERT_EQUAL( Next(min)->value, 2 );
  ASSERT_EQUAL( Next(r)->value, 100);
  ASSERT( Next(m) == nullptr);



  while (min) {
    cout << min->value << '\n';
    min = Next(min);
  }
}

void TestRootOnly() {
  NodeBuilder nb;
  Node* root = nb.CreateRoot(42);
  ASSERT( Next(root) == nullptr);
};


int main() {
  TestRunner tr;
  RUN_TEST(tr, Test1);
  RUN_TEST(tr, TestRootOnly);
  return 0;
}

