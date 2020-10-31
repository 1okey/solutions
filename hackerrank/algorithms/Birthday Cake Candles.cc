// https://www.hackerrank.com/challenges/birthday-cake-candles/problem

int birthdayCakeCandles(vector<int> candles) {
    int count = 0;
    int tallest = candles[0];
    for (int& c : candles)
    {
        if (c > tallest) {
            count = 1;
            tallest = c;
        } else if (c == tallest) {
            ++count;
        }
    }
    return count;
}
