package main

type MyQueue []int

func Constructor() MyQueue {
    return MyQueue{}
}


func (this *MyQueue) Push(x int)  {
    *this = append(*this, x)
}


func (this *MyQueue) Pop() int {
		tmp := (*this)[0]
		*this = (*this)[1:]
		return tmp
}


func (this *MyQueue) Peek() int {
    return (*this)[0]
}


func (this *MyQueue) Empty() bool {
    return len(*this) == 0
}
