// https://www.hackerrank.com/challenges/angry-professor/problem

string angryProfessor(int threshhold, vector<int> a) {
    int in_time = 0;

    for (int& n: a) {
        in_time += n <= 0 ? 1 : 0;
    }
    
    return in_time >= threshhold ? "NO" : "YES";
}