// https://www.hackerrank.com/challenges/drawing-book/problem

int pageCount(int n, int p) {
    if (p > n / 2) {
        int turns = (n - p) / 2;
        int is_first = ((n - p) == 1);
        return  n % 2 == 1 ? turns : turns + is_first;
    }
    else {
        return p / 2;
    }
}