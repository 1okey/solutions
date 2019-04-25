// In a 2 dimensional array grid, each value grid[i][j] represents the height of a building 
// located there. We are allowed to increase the height of any number of buildings, by any amount
// (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 

// At the end, the "skyline" when viewed from all four directions of the grid, i.e. 
// top, bottom, left, and right, must be the same as the skyline of the original grid. 
// A city's skyline is the outer contour of the rectangles formed by all the buildings 
// when viewed from a distance. See the following example.

// What is the maximum total sum that the height of the buildings can be increased?

// Example:
// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
// Output: 35
// Explanation: 
// The grid is:
// [ [3, 0, 8, 4], 
//   [2, 4, 5, 7],
//   [9, 2, 6, 3],
//   [0, 3, 1, 0] ]

// The skyline viewed from top or bottom is: [9, 4, 8, 7]
// The skyline viewed from left or right is: [8, 7, 9, 3]

// The grid after increasing the height of buildings without affecting skylines is:

// gridNew = [ [8, 4, 8, 7],
//             [7, 4, 7, 7],
//             [9, 4, 8, 7],
//             [3, 3, 3, 3] ]

// Notes:

// 1 < grid.length = grid[0].length <= 50.
// All heights grid[i][j] are in the range [0, 100].
// All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.

#include <vector>
#include <iostream>
#include <cmath>

using std::vector;
using std::min;
using std::abs;
using std::max;

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        size_t n = 0;
        size_t x_max = grid[0].size();
        size_t y_max = grid.size();
        
        vector<int> skyline_x;
        vector<int> skyline_y;
        skyline_x.reserve(x_max);
        skyline_y.reserve(y_max);
        
        // save skylines
        
        size_t x, y;
        while (n < y_max) {
            int mx = -1, my = -1;
            x = 0, y = 0;
            for (; y < y_max && x < x_max; ++x, ++y) {
                mx = max(mx, grid[y][n]);
                my = max(my, grid[n][x]);
            }
            
            skyline_x.push_back(mx);
            skyline_y.push_back(my);
            
            ++n;
        }
        
        int acc = 0;
        int height = 0;
        for (y = 0; y < y_max; ++y) {
            for (x = 0; x < x_max; ++x) {
                height = min(skyline_y[y], skyline_x[x]);
                acc += abs(height - grid[y][x]);
            }
        }       
            
        return acc;
    }
};