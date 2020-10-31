// https://www.hackerrank.com/challenges/diagonal-difference/problem
/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int lhs = 0, rhs = 0;
    for (size_t i = 0; i < arr.size(); ++i) 
    {
        lhs += arr[i][i];
        rhs += arr[i][arr.size() - i - 1];
    }
    return abs(lhs - rhs);
}