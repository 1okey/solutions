// https://www.hackerrank.com/challenges/equal-stacks/problem
/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int a1 = accumulate(h1.begin(), h1.end(), 0);
    int a2 = accumulate(h2.begin(), h2.end(), 0);
    int a3 = accumulate(h3.begin(), h3.end(), 0);
    
    if (a1 == a2 && a1 == a3) return a1;
    
    unordered_map<int, int> dict;
    dict[a1]++;
    dict[a2]++;
    dict[a3]++;

    for (int& n: h1) dict[a1 -= n]++;
    for (int& n: h2) dict[a2 -= n]++;
    
    for (int& n: h3) {
        if ( dict[a3 -= n] == 2) {
            return a3;            
        }
    }
    
    return 0;
}