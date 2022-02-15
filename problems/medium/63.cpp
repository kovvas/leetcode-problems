// Number: 63
// Name: Unique Paths II
// Tags: DP

// O(N*M) O(N*M)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < cols; ++i) {
            if (obstacleGrid[0][i] != 1) dp[0][i] = 1;
            else break;
        }
        for (int i = 0; i < rows; ++i) {
            if (obstacleGrid[i][0] != 1) dp[i][0] = 1;
            else break;
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
