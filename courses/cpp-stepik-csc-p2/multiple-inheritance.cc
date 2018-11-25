// Вам дана следующая иерархия классов:

struct Base { ... };

struct D1 : Base { ... };

struct D2 : Base { ... };

struct D3 : D1, D2 { ... };

// Напишите функцию D1BaseToD2Base, которая преобразует указатель типа Base на
// объект типа D3, который ссылается на экземпляр Base, соответствующий D1, в
// указатель, ссылающийся на экземпляр Base соответствующий D2.

Base const * D1BaseToD2Base( Base const * b ){
  return (Base*)(D2*)(D3*)(D1*) b;
}


// Предположим, что при разработке игры вам потребовался юнит "Челмедведосвин" (ManBearPig).
// Завершите разработку иерархии классов и реализуйте необходимые конструкторы.
// PS: В данном игровом контексте предполагается, что человек — не животное.

/* этот класс уже определён выше
struct Unit
{
    explicit Unit(size_t id)
        : id_(id)
    {}

    size_t id() const { return id_; }

private:
    size_t id_;
};
*/

struct Animal: virtual Unit {
  Animal(std::string const & name, size_t id)
    : name_(name), Unit(id)
  {}

  std::string const& name() const { return name_; }
private:
  std::string name_;
};

struct Man : virtual Unit {
  explicit Man(size_t id)
    : Unit(id)
  {}
};


struct Bear: public Animal {
  explicit Bear(size_t id)
    : Unit(id), Animal("bear", id)
  {}
};

struct Pig: public Animal {
  explicit Pig(size_t id)
    : Unit(id), Animal("pig", id)
  {}
};

struct ManBearPig: public Man, public Bear, public Pig {
  ManBearPig(size_t id)
    :  Man(id), Bear(id), Pig(id), Unit(id)
  {}
};





