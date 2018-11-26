#include <ostream>
#include <typeinfo>

// По аналогии с функцией printf с предыдущего степа напишите функцию print_values
// с переменным числом аргументов, которая для каждого аргумента выводит его тип
// и значение в поток std::ostream, который ей передан в качестве первого аргумента.
// Функция должна работать с произвольным числом аргументов.

void print_values(std::ostream & os){
    return;
}

template <typename Type, typename... Args>
void print_values(std::ostream & os, const Type& value, Args... args) 
{
    while(true){
        os << typeid(value).name() << ": " << value << '\n'; 
        return print_values(os, args...);
    }
}	
