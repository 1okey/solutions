// https://www.hackerrank.com/challenges/dynamic-array/problem

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> dyn_arr(n, vector<int>());
    vector<int> output;
    int type,x,y;
    int lastAnswer = 0;
    
    for (vector<int>& q : queries) {
        x = q[1];
        y = q[2];
        if (q[0] == 1) {
            dyn_arr[(x ^ lastAnswer) % n].push_back(y);
        }
        else {
            vector<int>& seq = dyn_arr[(x ^ lastAnswer) % n];
            lastAnswer = seq[y % seq.size()];
            output.push_back(lastAnswer);
        }
    }
    
    return output;
}