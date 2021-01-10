#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <set>

using namespace std;
using matrix = vector<vector<int>>;


void print_matrix(matrix& m) 
{
    for(auto& r: m) {
        for(auto& cell : r) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

matrix zero_fill(matrix& m)
{
    set<int> rows;
    set<int> cols;

    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            if (m[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int r: rows) {
        for(int& cell : m[r]) {
            cell = 0;
        }
    }

    for(int c: cols) {
        for(vector<int>& row : m) {
            row[c] = 0;
        }
    }

    return m;
}

int main() 
{

    vector<pair<matrix, matrix>> test_cases = {
        {
            {{1,0,3}, {1,2,3}, {1,2,3}},
            {{0,0,0}, {1,0,3}, {1,0,3}}
        }, 
        {
            {{1,0,3}, {1,2,3}, {0,2,3}, {1,0,3}},
            {{0,0,0}, {0,0,3}, {0,0,0}, {0,0,0}}  
        }
    };

    for (auto [actual, expected]: test_cases) {
        cout << (zero_fill(actual) == expected ? "True" : "False") << '\n';
    }

    return 0;
}