// https://www.hackerrank.com/challenges/simple-array-sum/problem

int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for (int& n : ar) sum += n;
    return sum;
}