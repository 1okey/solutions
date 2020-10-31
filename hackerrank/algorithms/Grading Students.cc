// https://www.hackerrank.com/challenges/grading/problem

vector<int> gradingStudents(vector<int> grades) {
    int delta;
    for(int& g : grades) {
        delta = (5 - (g % 5));
        if (delta < 3 && g >= 38) {
            g += delta;
        } 
    }
    return grades;
}