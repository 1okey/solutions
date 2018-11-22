#include <string>
#include <iostream>

using namespace std;
// Свяжите следующие классы в иерархию наследования: Character 
// (Персонаж), LongRange (Персонаж дальнего действия), Wizard 
// (Маг), SwordsMan (Мечник), Archer (Лучник).
// Обратите внимание на методы, объявленные в классах — они 
// приведены в качестве описания интерфейса, которым должны 
// обладать классы. Не изменяйте объявлений методов — они 
// даны как подсказка, просто добавьте наследование в 
// определения классов.

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange : Character
{
    unsigned range() const;
};

struct SwordsMan : Character
{
    unsigned strength() const;    
};

struct Wizard : LongRange
{
    unsigned mana() const;
};

struct Archer: LongRange
{
    unsigned accuracy() const;
};


// Вам дан класс Foo:
//
 struct Foo {
     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 protected:
     Foo(const char *msg) : msg(msg) { }
 private:
     const char *msg;
 };
// Как видно, создатель класса не хотел чтобы его использовали и "спрятал" конструктор класса.
// Но вам очень нужен объект этого класса, чтобы передать его в функцию foo_says:
//
// void foo_says(const Foo& foo) { foo.say(); }
// В этом задании вам нужно реализовать функцию get_foo (сигнатура которой намерено не
// приводится в задании полностью, вам нужно подумать и вывести ее самостоятельно) так,
// чтобы следующий код компилировался и работал:
//
// foo_says(get_foo(msg));
// Где msg — произвольная C-style строка.

struct Bar : Foo
{
    Bar(const char*msg): Foo(msg)
    {}
    char * msg;
};

Bar get_foo(const char *msg) {
    Bar bar(msg);
    return bar;
}
