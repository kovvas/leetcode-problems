// Number: 542
// Name: 01 Matrix
// Tags: BFS, DP

// O(m*n) O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        // DP from top left
        vector<vector<int>> answer(rows, vector<int> (cols, 10000));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) answer[row][col] = 0;
                else {
                    if (row > 0)
                        answer[row][col] = min(answer[row][col], answer[row - 1][col] + 1);
                    if (col > 0)
                        answer[row][col] = min(answer[row][col], answer[row][col - 1] + 1);
                }
            }
        }
        // DP from bottom right
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if (row < rows - 1)
                    answer[row][col] = min(answer[row][col], answer[row + 1][col] + 1);
                if (col < cols - 1)
                    answer[row][col] = min(answer[row][col], answer[row][col + 1] + 1);
            }
        }
        
        return answer;
    }
};

// O(m*n) O(m*n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        // DP from top left
        vector<vector<int>> answer(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> cells;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    answer[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }
        
        while (!cells.empty()) {
            auto cur = cells.front();
            cells.pop();
            for (int i = 0; i < 4; ++i) {
                int new_row = cur.first + dir[i][0];
                int new_col = cur.second + dir[i][1];
                if (new_row >= 0 && new_col >= 0 && new_row < rows && new_col < cols) {
                    if (answer[new_row][new_col] > answer[cur.first][cur.second] + 1) {
                        answer[new_row][new_col] = answer[cur.first][cur.second] + 1;
                        cells.push({new_row, new_col});
                    }
                }
            }
        }
        
        return answer;
    }
};
