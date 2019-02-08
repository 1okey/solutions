// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
//
// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
//
//
// Example 1:
//
// Input:
// matrix = [
//   [1,2,3,4],
//   [5,1,2,3],
//   [9,5,1,2]
// ]
// Output: True
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.

bool isToeplitzMatrix(int** mtx, int rs, int *cs) {
    for(int m = 1; m < rs; m++)
        for(int k = 1; k < *cs &&  m < rs; k++)
            if(mtx[m][k] != mtx[m - 1][k - 1]) 
                return false;    
    return true;
}
