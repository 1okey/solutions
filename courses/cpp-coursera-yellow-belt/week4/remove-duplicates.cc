#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

// Напишите шаблонную функцию RemoveDuplicates, принимающую по ссылке вектор elements объектов
// типа T и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.
//
// Гарантируется, что объекты типа T можно сравнивать с помощью операторов ==, !=, < и >.

template <typename T>
void RemoveDuplicates(vector<T>& elements){
  set<T> s = {elements.begin(), elements.end()};
  elements = vector<T>{s.begin(), s.end()};
}

// ИЛИ

template <typename T>
void RemoveDuplicates(vector<T>& elements){
  sort(elements.begin(), elements.end());
  elements.erase(unique(elements.begin(), elements.end()),
                 elements.end());
}

