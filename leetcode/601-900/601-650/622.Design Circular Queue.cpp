// Design your implementation of the circular queue. The circular queue is a linear data structure in which 
// the operations are performed based on FIFO (First In First Out) principle and the last position is connected 
// back to the first position to make a circle. It is also called "Ring Buffer".

// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
// In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space 
// in front of the queue. But using the circular queue, we can use the space to store new values.

// Your implementation should support following operations:

// MyCircularQueue(k): Constructor, set the size of the queue to be k.
// Front: Get the front item from the queue. If the queue is empty, return -1.
// Rear: Get the last item from the queue. If the queue is empty, return -1.
// enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
// deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
// isEmpty(): Checks whether the circular queue is empty or not.
// isFull(): Checks whether the circular queue is full or not.

#include <iostream>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class MyCircularQueue {
private:
    int _M_size;
    int * _M_data;
    int _M_start;
    int _M_end;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) :
        _M_size(k),
        _M_data(new int[k]),
        _M_start(-1),
        _M_end(-1)
    {}
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            _M_start = 0;

        _M_end = (_M_end + 1) % _M_size;
        _M_data[_M_end] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        if (_M_start == _M_end) {
            _M_start = -1;
            _M_end = -1;
            return true;
        }

        _M_start = (_M_start + 1) % _M_size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return _M_data[_M_start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        return _M_data[_M_end];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return _M_start == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (_M_end + 1) % _M_size == _M_start;
    }

    ~MyCircularQueue() {
        delete [] _M_data;
    }
};
