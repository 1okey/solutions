#include <utility>

//Напишите функцию apply, которая принимает некоторую функцию / функциональный объект,
// а так же аргументы для вызова этого объекта, и вызывает его, используя perfect forwarding.

// Примечание: гарантируется, что количество аргументов, переданных в apply, совпадает
// с количеством аргументов у функции/функционального объекта. При этом у функции может
// быть произвольное число аргументов.

// Hint: ﻿в данном задании нужно использовать новый синтаксис определения функций.

template<typename Func, typename... Types>
auto apply ( Func f, Types&&... t ) -> decltype(f(std::forward<Types>(t)...))
{
    return f(std::forward<Types>(t)...);
}	

int main(){
	auto fun = [](std::string a, std::string const& b) { return a += b; };

	std::string s("world!");
	s = apply(fun, std::string("Hello, "), s);
	return 0
}
