// https://www.hackerrank.com/challenges/c-class-templates/problem

template<typename T>
class AddElements {
private:
    T _val;
public:
    AddElements(T val) 
        : _val(val)
    {}
    T add(const T& other) { 
        return _val + other;
    }
    T concatenate(const T& other) { return add(other); }
};
