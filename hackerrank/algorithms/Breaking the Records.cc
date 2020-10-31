// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

vector<int> breakingRecords(vector<int>& scores) {
    int min_ = scores.front();
    int max_ = scores.front();
    int min_count = 0;
    int max_count = 0;

    for(int& score: scores)
    {
        if (score > max_) {
            ++max_count;
            max_ = score;
        } 
        else if (score < min_) {
            ++min_count;
            min_ = score;
        }
    }

    return vector<int>{max_count, min_count};
}