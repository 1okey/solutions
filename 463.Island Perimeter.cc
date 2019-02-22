static int asyncx = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    using Grid = vector<vector<int>>;
    int getNeighbourAmmount(Grid& grid, int y, int x){
        int count = 0;
        if(y - 1 >= 0)              count += grid[y - 1][x];
        if(x - 1 >= 0)              count += grid[y][x - 1];
        if(x + 1 < grid[0].size())  count += grid[y][x + 1];
        if(y + 1 < grid.size())     count += grid[y + 1][x];
        return count;
    }

    int islandPerimeter(Grid& grid) {
        int perimeter = 0;
        for(size_t i = 0; i < grid.size(); ++i){
            for(size_t j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 0){
                    continue;
                } else {
                    perimeter += 4 - getNeighbourAmmount(grid, i , j);
                }
            }
        }
        return perimeter;
    }
};
