// При помощи typedef определите тип ComplexFunction, который является указателем
// на функцию, которая принимает int и указатель на функцию, принимающую double
// и возвращающую int, и возвращает указатель на функцию, которая принимает
// char const * и возвращает int *.

typedef int(*Callback)(double);
typedef int*(*ReturnFunc)(char const*);
typedef ReturnFunc(*ComplexFunction)(int, Callback);

