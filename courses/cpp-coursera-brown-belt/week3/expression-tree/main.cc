#include "Common.h"
#include "test_runner.h"

#include <sstream>

using namespace std;

class BinaryExpr: public Expression {
public:
  BinaryExpr(ExpressionPtr& lhs, ExpressionPtr& rhs)
    : lhs(move(lhs)), rhs(move(rhs))
  {}
protected:
  ExpressionPtr lhs;
  ExpressionPtr rhs;
};

class ConstExpr: public Expression {
public:
  ConstExpr(int value)
    : value(value)
  {}

  int Evaluate() const override {
    return value;
  }

  std::string ToString() const override {
    return std::to_string(value);
  }

  ~ConstExpr() override {}
private:
  int value;
};

class MulExpr: public BinaryExpr {
public:
  MulExpr(ExpressionPtr& lhs, ExpressionPtr& rhs)
    : BinaryExpr(lhs, rhs)
  {}

  int Evaluate() const override {
    return lhs->Evaluate() * rhs->Evaluate();
  }

  std::string ToString() const override {
    return "(" + lhs->ToString() + ")" + "*" + "(" +rhs->ToString() + ")";
  }
};

class SumExpr: public BinaryExpr {
public:
  SumExpr(ExpressionPtr& lhs, ExpressionPtr& rhs)
    : BinaryExpr(lhs, rhs)
  {}

  int Evaluate() const override {
    return lhs->Evaluate() + rhs->Evaluate();
  }

  std::string ToString() const override {
    return "(" + lhs->ToString() + ")" + "+" + "(" +rhs->ToString() + ")";
  }
};

ExpressionPtr Value(int value){
  return make_unique<ConstExpr>(value);
}
ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right){
  return make_unique<SumExpr>(left, right);
}
ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right){
  return make_unique<MulExpr>(left, right);
}


string Print(const Expression* e) {
  if (!e) {
    return "Null expression provided";
  }
  stringstream output;
  output << e->ToString() << " = " << e->Evaluate();
  return output.str();
}

void Test() {
  ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
  ASSERT_EQUAL(Print(e1.get()), "(2)*((3)+(4)) = 14");

  ExpressionPtr e2 = Sum(move(e1), Value(5));
  ASSERT_EQUAL(Print(e2.get()), "((2)*((3)+(4)))+(5) = 19");

  ASSERT_EQUAL(Print(e1.get()), "Null expression provided");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, Test);
  return 0;
}
