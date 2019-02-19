static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& row: A){
            for( size_t i = 0, j = row.size() - 1;
                i <= row.size() / 2  && i <= j
                ;++i, --j ){
                int& a = row[i];
                int& b = row[j];
                swap(a,b);
                a = !a;
                if(i != j)
                    b = !b;
            }
        }
        return A;
    }
};

