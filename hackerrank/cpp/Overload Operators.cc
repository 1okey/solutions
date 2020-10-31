// https://www.hackerrank.com/challenges/overload-operators/problem

Complex operator+(const Complex & lhs, const Complex & rhs) {
    Complex c;
    c.a = (lhs.a + rhs.a);
    c.b = (lhs.b + rhs.b);
    return c;
}

ostream& operator<<(ostream & os, const Complex& c){
    os << c.a << "+i" << c.b; 
    return os;
}

