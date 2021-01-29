#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::stack;
using std::cout;

class SetOfStacks {
private:
    const int MAX_SIZE = 3;
    vector<stack<int> > stacks;
    int ptr;
public:
    SetOfStacks()
        : ptr(0)
    {
        stacks.push_back(stack<int>());
    }

    void push(int value)
    {
        while(ptr < stacks.size() && stacks[ptr].size() == SetOfStacks::MAX_SIZE) {
            ++ptr;
        }

        if (ptr >= stacks.size()) {
            stacks.push_back(stack<int>());
        }

        stacks[ptr].push(value);
    }

    int pop() { 
        return popAt(ptr); 
    }

    int popAt(int index)
    {
        if (index > ptr) {
            return -1;
        }

        if (stacks[ptr].size() == 0) {
            stacks.pop_back();
            --ptr;
        }

        int top = stacks[index].top();
        stacks[index].pop();

        return top;
    }
};


int main()
{
    SetOfStacks stack = SetOfStacks();
    stack.push(4);
    stack.push(6);
    stack.push(9);
    stack.push(3);
    assert(stack.popAt(0) == 9);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.popAt(0) == 6);
    assert(stack.popAt(1) == 2);
    assert(stack.popAt(2) == 3);
}