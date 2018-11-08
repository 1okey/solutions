#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

// Напишите шаблонную функцию FindGreaterElements, принимающую множество elements объектов
// типа T и ещё один объект border типа T и возвращающую вектор из всех элементов множества,
// бо́льших border, в возрастающем порядке.

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
   auto it = begin(elements);
   for (; it != end(elements) && *it <= border; ++it);
   return vector<T>{it, elements.end()};
}

