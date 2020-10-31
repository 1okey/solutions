// https://www.hackerrank.com/challenges/plus-minus/problem

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
    float below = 0.0f, zero = 0.0f, above = 0.0f;
    for (int& n : arr)
    {
        below += n < 0;
        zero += n == 0;
        above += n > 0;
    }

    cout << above / arr.size() << '\n'
         << below / arr.size() << '\n'
         << zero / arr.size() << '\n'; 
}