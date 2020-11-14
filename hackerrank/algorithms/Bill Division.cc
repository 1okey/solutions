// https://www.hackerrank.com/challenges/bon-appetit/problem

void bonAppetit(vector<int> bill, int k, int b) {
    int sum = 0;
    for (int i = 0; i < bill.size(); ++i) {
        sum += i != k ? bill[i] : 0;
    }
    
    int charged = sum / 2;
    cout << (charged == b ? "Bon Appetit" : to_string(abs(b - charged))) <<'\n';
}
