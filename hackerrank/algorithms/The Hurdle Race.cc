// https://www.hackerrank.com/challenges/the-hurdle-race/problem

int hurdleRace(int k, vector<int> height) {
    int max_ = *max_element(height.begin(), height.end());
    
    return max_ > k ? max_ - k : 0;
}
