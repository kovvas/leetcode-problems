// Number: 64
// Name: Minimum Path Sum
// Tags: DP

// O(m*n) O(1)
class Solution {
public:    
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = grid.size() - 1; i >= 0; --i) {
            for (int j = grid[0].size() - 1; j >= 0; --j) {
                if (i == grid.size() - 1) {
                    // last row
                    if (j == grid[0].size() - 1) continue;
                    grid[i][j] += grid[i][j + 1]; 
                } else {
                    if (j == grid[0].size() - 1) {
                        grid[i][j] += grid[i + 1][j];
                    } else grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }
        return grid[0][0];
    }
};
