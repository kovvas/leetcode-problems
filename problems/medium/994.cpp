// Number: 994
// Name: Rotting Oranges
// Tags: BFS

// O(N), O(N)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> rotten;
        int freshCounter = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) rotten.push({i, j});
                else if (grid[i][j] == 1) freshCounter++;
            }
        }
        if (!freshCounter) return 0;
        if (rotten.empty() && freshCounter) return -1;
        int timeCounter = 0;
        int rottenCounter = rotten.size();
        while(!rotten.empty()) {
            int newRottenCounter = 0;
            while (rottenCounter != 0) {
                auto curRotten = rotten.front();
                rotten.pop();
                int i = curRotten[0];
                int j = curRotten[1];
                if (i > 0 && grid[i - 1][j] == 1) {
                    rotten.push({i - 1, j});
                    newRottenCounter++;
                    grid[i - 1][j] = 2;
                    freshCounter--;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    rotten.push({i, j - 1});
                    newRottenCounter++;
                    grid[i][j - 1] = 2;
                    freshCounter--;
                }
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    rotten.push({i + 1, j});
                    newRottenCounter++;
                    grid[i + 1][j] = 2;
                    freshCounter--;
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    rotten.push({i, j + 1});
                    newRottenCounter++;
                    grid[i][j + 1] = 2;
                    freshCounter--;
                }
                rottenCounter--;
            }
            if (!rotten.empty()) timeCounter++;
            rottenCounter = newRottenCounter;
        }
        return freshCounter == 0 ? timeCounter : -1;
    }
};
