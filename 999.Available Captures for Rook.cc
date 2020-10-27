// https://leetcode.com/problems/available-captures-for-rook/

class Solution {
public:
    bool inBounds(int size, int x, int y)
    {
        return !(x == size || y == size || x < 0 || y < 0);
    }
    
    int getCaptures(vector<vector<char>>& board, int x, int y, int inc_x, int inc_y) {
        int dx = inc_x;
        int dy = inc_y;
    
        while(inBounds(board.size(), x + dx, y + dy) && board[x + dx][y + dy] == '.') 
        { 
            dx += inc_x; 
            dy += inc_y; 
        }
        
        return inBounds(board.size(), x + dx, y + dy) && board[x + dx][y + dy] == 'p';    
    }
    
    int numRookCaptures(vector<vector<char>>& board) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        for (size_t x = 0; x < board.size(); ++x)
        {
            for(size_t y = x; y < board.size(); ++y)
            {
                if (board[x][y] == 'R' || board[y][x] == 'R') {
                    int rock_x = board[x][y] == 'R' ? x : y;
                    int rock_y = board[x][y] == 'R' ? y : x;
                    int count = 0;
                    
                    count += getCaptures(board, rock_x, rock_y, 1, 0);
                    count += getCaptures(board, rock_x, rock_y, -1, 0);
                    count += getCaptures(board, rock_x, rock_y, 0, 1);
                    count += getCaptures(board, rock_x, rock_y, 0, -1);
                    
                    return count;
                }
            }
        }
        
        return 0;
    }
};