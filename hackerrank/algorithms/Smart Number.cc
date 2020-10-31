// https://www.hackerrank.com/challenges/smart-number/problem

bool is_smart_number(int num) {
    int val = (int) sqrt(num);
    return num / val == val;
}

int main() {
    
    int test_cases;
    cin >> test_cases;
    int num;
    for(int i = 0; i < test_cases; i++) {
        cin >> num;
        bool ans = is_smart_number(num);
        if(ans) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}