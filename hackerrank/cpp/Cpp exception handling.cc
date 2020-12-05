// https://www.hackerrank.com/challenges/cpp-exception-handling/problem

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    } catch (...) {
        cout << "largest proper divisor is not defined for n=" << n << '\n';
    }
    cout << "returning control flow to caller" << '\n';
}
