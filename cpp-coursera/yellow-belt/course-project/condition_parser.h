#pragma once

#include <memory>
#include <iostream>
#include "token.h"
#include "date.h"

enum class LogicalOperation {
    Or,
    And
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node {
public:
    Node();
    virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();

