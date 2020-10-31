// https://www.hackerrank.com/challenges/classes-objects/problem

class Student {
private:
    int score;
public:
    Student(): score(0) {}
    void input(){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        score = a + b + c + d + e;
    }
    int calculateTotalScore(){
        return score;
    }
};
