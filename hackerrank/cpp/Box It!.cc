// https://www.hackerrank.com/challenges/box-it/problem

class Box {
private:
    int l,b,h;
public:
    Box(): l(0),b(0),h(0) {}
    Box(int len, int breadth, int height)
    : l(len), b(breadth), h(height)
    {}
    Box(Box & other) {
        l = other.getLength();
        b = other.getBreadth();
        h = other.getHeight();
    }
    
    long long CalculateVolume() {
        return (long long)l * (long long)b * (long long)h;
    }

    int getLength()     { return l; }
    int getBreadth()   { return b; }
    int getHeight()    { return h; }
};

bool operator<(Box & lhs, Box & rhs) {
    return make_tuple(lhs.getLength(), lhs.getBreadth(), lhs.getHeight())
         < make_tuple(rhs.getLength(), rhs.getBreadth(), rhs.getHeight());
}

ostream& operator<<(ostream& os, Box & b) {
    os << b.getLength() << ' ' << b.getBreadth() << ' ' << b.getHeight();
    return os;
}
