// https://www.hackerrank.com/challenges/a-very-big-sum/problem

long aVeryBigSum(vector<long> ar) {
    long long sum = 0;
    for (long& n : ar) sum += n;
    return sum;
}