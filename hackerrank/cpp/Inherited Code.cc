// https://www.hackerrank.com/challenges/inherited-code/problem
class BadLengthException: std::exception {
private:
    int l;
public:
    BadLengthException(int length): l(length) {}
    string what() {
        return to_string(l);
    }
};