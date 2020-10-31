// https://www.hackerrank.com/challenges/compare-the-triplets/problem

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int a_points = 0;
    int b_points = 0;

    for (size_t i = 0; i < a.size(); ++i)
    {
        a_points += a[i] > b[i];
        b_points += b[i] > a[i];
    }

    return {a_points, b_points};
}

