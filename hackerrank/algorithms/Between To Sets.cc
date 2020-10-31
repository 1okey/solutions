// https://www.hackerrank.com/challenges/between-two-sets/problem

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int lhs, int rhs) {
    return lhs * (rhs / gcd(lhs, rhs));
}

int getTotalX(vector<int> a, vector<int> b) {
    int counter = 0;
    int _gcd = b.front(), _lcm = a.front();
    
    // finding lcm for a
    for(unsigned i = 1; i < a.size(); ++i) _lcm = lcm(_lcm, a[i]);
    // finding gcd for b
    for(unsigned i = 1; i < b.size(); ++i) _gcd = gcd(_gcd, b[i]);
    
    // cerr << _gcd << ' ' << _lcm << endl;
    for (int n = _lcm; n <= _gcd; n += _lcm) {
        // cerr << _gcd % n << ' ';
        if (_gcd % n == 0 ) counter++;
    }

    return counter;
}