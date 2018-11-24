#include <iostream>

// Шаблонный класс Array может хранить объекты любого типа, для которого определён
// конструктор копирования, в том числе и другой Array, например, Array< Array<int> >.
// Глубина вложенности может быть произвольной. Напишите шаблонную функцию (или несколько)
// flatten, которая принимает на вход такой "многомерный" Array неизвестной заранее 
// глубины вложенности и выводит в поток out через пробел все элементы, хранящиеся на самом нижнем уровне.

template <typename T>
void flatten(const T& item, std::ostream& out){
    out << item << ' ';
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
    for (size_t i = 0; i < array.size(); ++i){
        flatten(array[i], out);
    }
}
