#pragma once

#include "date.h"
#include "condition_parser.h"
#include <string>

class EmptyNode : public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const std::string& event) override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& op, const Date& date);
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    Comparison op;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& op, const std::string& event);
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    Comparison op;
    string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node> left, const shared_ptr<Node> right);
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    LogicalOperation op;
    shared_ptr<Node> left, right;
};
