#include "node.h"

Node::Node(){}
EmptyNode::EmptyNode(){}

bool EmptyNode::Evaluate(const Date& date, const std::string& event)
{
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& op, const Date& date)
    : op(op), date_(date){}
bool DateComparisonNode::Evaluate(const Date& date, const std::string& event)
{
    bool result;
    switch (op) {
        case Comparison::Less: result = date < date_; break;
        case Comparison::LessOrEqual: result = date <= date_; break;
        case Comparison::Greater: result = date > date_; break;
        case Comparison::GreaterOrEqual: result = date >= date_; break;
        case Comparison::Equal: result = date == date_; break;
        case Comparison::NotEqual: result = date != date_; break;
        default: throw runtime_error("Unknown error in DateComparisonNode");
    }
    return result;
}

EventComparisonNode::EventComparisonNode(const Comparison& op, const std::string& event)
    : op(op), event_(event){}
bool EventComparisonNode::Evaluate(const Date& date, const std::string& event)
{
    bool result;
    switch (op) {
        case Comparison::Less: result = event < event_; break;
        case Comparison::LessOrEqual: result = event <= event_; break;
        case Comparison::Greater: result = event > event_; break;
        case Comparison::GreaterOrEqual: result = event >= event_; break;
        case Comparison::Equal: result = event == event_; break;
        case Comparison::NotEqual: result = event != event_; break;
        default: throw runtime_error("Unknown error in DateComparisonNode");
    }
    return result;
}
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node> left, const shared_ptr<Node> right)
    : op(op), left(left), right(right){}
bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event)
{
    bool result;
    switch(op){
        case LogicalOperation::And:
            result = left->Evaluate(date,event) && right->Evaluate(date,event);
            break;
        case LogicalOperation::Or:
            result = left->Evaluate(date,event) || right->Evaluate(date,event);
            break;
        default: throw runtime_error("Unknown error in DateComparisonNode");
    }
    return result;
}
