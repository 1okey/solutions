static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool in_bound(size_t size, size_t i, size_t j){
        return i < size && j < size;
    }

    vector<int> sortArrayByParityII(vector<int>& a) {
        for(size_t i = 0, j = 1; in_bound(a.size(),i,j);){
            if(a[i] % 2 == 1 && a[j] % 2 == 0){
                swap(a[i], a[j]);
                i += 2;
            }

            if(!in_bound(a.size(),i,j)) break;

            if(a[j] % 2 == 0 && a[i] % 2 == 1){
                swap(a[i], a[j]);
                j += 2;
            }

            if(a[i] % 2 == 0) i += 2;
            if(a[j] % 2 == 1) j += 2;

        }
        return a;
    }
};

