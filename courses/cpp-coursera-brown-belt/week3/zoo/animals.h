#include <string>

class Animal {
public:
  virtual std::string Voice() const {
    return "Not implemented yet";
  }
  virtual ~Animal() {}
};


class Tiger: public Animal {
public:
  std::string Voice() const override {
    return "Rrrr";
  }
};


class Wolf: public Animal {
public:
  std::string Voice() const override {
    return "Wooo";
  }
};


class Fox: public Animal {
public:
  std::string Voice() const override {
    return "Tyaf";
  }
};
