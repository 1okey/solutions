// https://www.hackerrank.com/challenges/operator-overloading/problem

struct Matrix {
    std::vector<vector<int>> a;
    Matrix operator+(Matrix& other) {
        Matrix sum;
        for(size_t i = 0; i < a.size(); ++i) {
            vector<int> row(a[i].size(), 0);
            for(size_t j = 0; j < a[i].size() ; ++j) {
                row[j] = a[i][j] + other.a[i][j];
            }
            sum.a.push_back(row);
        }
        return sum;
    }
};
