#include <algorithm>

// Дополните класс Array перемещающим конструктором и перемещающим оператором присваивания.

#include <algorithm>

template<class T>
struct Array
{
    explicit Array(size_t size = 0);
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array();

    size_t size() const;
    T &         operator[](size_t i);
    T const&    operator[](size_t i) const;
    
    void swap(Array& str){
        std::swap(size_, str.size_);
        std::swap(data_, str.data_);
    }

    Array(Array&& tmp){
        swap(tmp);
    }
    
    Array& operator=(Array&& tmp){
        clear();
        swap(tmp);
        return (*this);
    }

private:
    void clear(){
        delete [] data_;
        size_ = 0;
        data_ = nullptr;
    }
    size_t  size_ = 0;
    T *     data_ = nullptr;    
};
