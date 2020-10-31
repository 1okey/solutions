// https://www.hackerrank.com/challenges/2d-array/problem

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int _max = INT_MIN;
    unsigned i = 0, j = 0;
    for (; i < arr.size() - 2; ++i) {
        for(j = 0; j < arr[0].size() - 2; ++j) {
            _max = max(_max, (
                arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                arr[i + 1][j + 1] +
                arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]
            ));
        }
    }

    return _max;
}