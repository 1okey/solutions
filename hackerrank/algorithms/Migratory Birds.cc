// https://www.hackerrank.com/challenges/migratory-birds/problem

int migratoryBirds(vector<int> arr) {
    int max_ = *max_element(arr.begin(), arr.end());
    vector<int> ranks(max_ + 1, 0);
    for (int& n : arr) {
        ++ranks[n];
    }
    
    int freq = max_;
    for(int number = ranks.size() - 2; number >= 0; --number) {
        if (ranks[number] >= ranks[freq]) {
            freq = min(number, freq);
        }    
    }

    return freq;
}
