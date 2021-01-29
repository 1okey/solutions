#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;

class MinStack {
private:
    vector<int> values;
    vector<int> mins;
public:
    void push(int value)
    {
        int min_ = std::min(value, (mins.size() == 0 ? value : mins.back()));
        mins.push_back(min_);
        values.push_back(value);
    }

    int pop()
    {
        int top = values.back();

        values.pop_back();
        mins.pop_back();

        return top;
    }

    int min()
    {
        return mins.back();
    }
};

int main()
{
    MinStack stack = MinStack();
    stack.push(4);
    stack.push(6);
    assert(stack.min() == 4);
    stack.push(9);
    stack.push(3);
    assert(stack.min() == 3);
    stack.pop();
    assert(stack.min() == 4);
    stack.push(1);
    stack.push(2);
    assert(stack.min() == 1);
    stack.pop();
    stack.pop();
    assert(stack.min() == 4);
}