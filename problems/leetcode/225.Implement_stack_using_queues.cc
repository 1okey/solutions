class MyStack {
public:
    struct node {
        node(node* prev, int value)
            : prev(prev), value(value)
        {}
        node* prev = nullptr;
        int value;
    };

    /** Initialize your data structure here. */
    MyStack()
    {}

    /** Push element x onto stack. */
    void push(int x) {
        node * new_node = new node(_top, x);
        _top = new_node;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        node * top = _top;
        _top = _top->prev;
        int val = top->value;
        delete top;
        return val;
    }

    /** Get the top element. */
    int top() {
        return _top->value;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _top == nullptr;
    }

    ~MyStack(){
        while(!empty()) pop();
    }
private:
    node * _top = nullptr;
};

