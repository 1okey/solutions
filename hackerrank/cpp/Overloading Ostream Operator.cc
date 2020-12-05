// https://www.hackerrank.com/challenges/overloading-ostream-operator/problem

ostream& operator<<(ostream& os, Person& p) {
    os << "first_name=" << p.get_first_name() << ',' 
        << "last_name=" << p.get_last_name();
    return os;    
}