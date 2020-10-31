// https://www.hackerrank.com/challenges/strings-xor/problem

string strings_xor(string s, string t) {
    vector<char> result;
    result.reserve(s.size());

    for(int i = 0; i < s.size(); i++) {
        result.push_back(s[i] == t[i] ? '0' : '1');
    }

    return string{result.begin(), result.end()};
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << strings_xor(s, t) << endl;
    return 0;
}
