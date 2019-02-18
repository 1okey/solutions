#include <stddef.h>

static int asynx = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
        : size_(0)    ,
          capacity_(1),
          min_indx_(0),
          data_(new int [capacity_])
    {
    }

    void push(int x)
    {
        if(size_ == capacity_){
            resize();
        }
        data_[size_] = x;
        min_indx_ = data_[min_indx_] < data_[size_] ? min_indx_ : size_;
        ++size_;
    }

    void pop()
    {
        if(size_ == 0){
            throw std::out_of_range("Can't pop empty stack");
        }
        --size_;
        if(min_indx_ == size_){
          min_indx_ = 0;
          for(size_t i = 0; i < size_; ++i){
            min_indx_ = data_[min_indx_] < data_[i] ? min_indx_ : i;
          }
        }

    }

    int top()
    {
        if(size_ == 0){
            throw std::out_of_range("Can't get top of empty stack");
        }
        return data_[size_ - 1];
    }

    int getMin() const
    {
        if(size_ == 0){
            throw std::out_of_range("Can't get min of empty stack");
        }
        return data_[min_indx_];
    }

    ~MinStack(){
        delete [] data_;
    }
private:
    void resize(){
        capacity_ *= 2;
        int* new_data = new int [capacity_];
        for(size_t i = 0; i < size_; ++i){
          new_data[i] = data_[i];
        }
        int* tmp = data_;
        data_ = new_data;
        delete [] tmp;
    }

    size_t size_;
    size_t capacity_;
    size_t min_indx_ = 0;
    int * data_;
};
