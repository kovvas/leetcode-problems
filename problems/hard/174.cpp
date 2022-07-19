// Number: 174
// Name: Dungeon Game
// Tags: DP

// O(N*M) O(N*M)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        int dp[rows][cols];
        dp[rows - 1][cols - 1] = -dungeon[rows - 1][cols - 1] + 1;
        if (dp[rows - 1][cols - 1] <= 0) dp[rows - 1][cols - 1] = 1;
        for (int i = cols - 2; i >= 0; --i) {
            dp[rows - 1][i] = -dungeon[rows - 1][i] + dp[rows - 1][i + 1];
            if (dp[rows - 1][i] <= 0) dp[rows - 1][i] = 1;
        }
        for (int i = rows - 2; i >= 0; --i) {
            dp[i][cols - 1] = -dungeon[i][cols - 1] + dp[i + 1][cols - 1];
            if (dp[i][cols - 1] <= 0) dp[i][cols - 1] = 1;
        }
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = cols - 2; j >= 0; --j) {
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                if (right >= 0 && down >= 0)
                    dp[i][j] = -dungeon[i][j] + min(right, down);
                if (right < 0 && down < 0)
                    dp[i][j] = -dungeon[i][j] + max(right, down);
                if (right >= 0 && down < 0)
                    dp[i][j] = -dungeon[i][j] + right;
                if (right < 0 && down >= 0)
                    dp[i][j] = -dungeon[i][j] + down;
                if (dp[i][j] <= 0) dp[i][j] = 1;
            }
        }
        if (dp[0][0] <= 0) return 1;
        return dp[0][0];
    }
};
