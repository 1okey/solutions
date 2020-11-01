#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> ar(n);
    vector<int> buckets(n,0);
    int result = 0, remainder = 0, complement = 0, num = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;
        remainder = num % k;
        complement = remainder == 0 ? k : remainder;
        result += buckets[k - complement];
        buckets[remainder]++;
    }

    fout << result << "\n";
    fout.close();

    return 0;
}
