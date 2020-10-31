// https://www.hackerrank.com/challenges/mini-max-sum/problem

void miniMaxSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long min_ = 0, max_ = 0;
    for(int i = 0, j = 1; j < arr.size(); ++i, ++j) {
        min_ += arr[i];
        max_ += arr[j];
    }
    cout << min_ << ' ' << max_ << '\n';
} 