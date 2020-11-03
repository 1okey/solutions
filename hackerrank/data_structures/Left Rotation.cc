// https://www.hackerrank.com/challenges/array-left-rotation/problem

vector<int> rotateLeft(int d, const vector<int>& arr) {
    vector<int> rotated(arr.size(), 0);

    d %= arr.size();
    for (size_t i = arr.size() - d, j = 0; i < arr.size(); ++i, ++j) {
        rotated[i] = arr[j];
    }
    for (size_t i = 0; i < arr.size() - d; ++i) {
        rotated[i] = arr[i + d];
    }
    
    return rotated;
}
