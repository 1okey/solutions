#pragma once

#include <memory>
#include <string>

// Базовый класс арифметического выражения
class Expression {
public:
  virtual ~Expression() = default;
  virtual int Evaluate() const = 0;
  virtual std::string ToString() const = 0;
};

using ExpressionPtr = std::unique_ptr<Expression>;

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
    return std::to_string(value)  ;
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

ExpressionPtr Value(int value);
ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right);
ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right);
