// Number: 980
// Name: Unique Path III
// Tags: DP


// O(4^M) O(M) where M - number of cells
class Solution {
public:
    int rows = 0;
    int cols = 0;
    int total_cells = 0;
    int paths = 0;
    vector<vector<int>> visited;
    
    bool isCellValid(int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols && visited[row][col] >= 0;
    }
    
    void backtracking(int row, int col, int remained) {
        if (!isCellValid(row, col)) return;
        if (visited[row][col] == 2 && remained == 1) {
            paths++;
            return;
        }
        int temp = visited[row][col];
        visited[row][col] = -2;
        remained--;
        backtracking(row + 1, col, remained);
        backtracking(row - 1, col, remained);
        backtracking(row, col + 1, remained);
        backtracking(row, col - 1, remained);
        visited[row][col] = temp;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int start_row = 0;
        int start_col = 0;
        visited = grid;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] >= 0) total_cells++;
                if (grid[i][j] == 1) {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        backtracking(start_row, start_col, total_cells);
        return paths;
    }
};
