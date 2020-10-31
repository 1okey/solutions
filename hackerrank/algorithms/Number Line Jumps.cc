// https://www.hackerrank.com/challenges/kangaroo/problem

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v2 == v1 || (v1 < v2 && x1 < x2)) return "NO";
    
    return  ((x2 - x1) % (v1 - v2)) == 0 ? "YES" : "NO";
}