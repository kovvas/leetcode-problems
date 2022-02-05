// Number: 73
// Name: Set Matrix Zeroes
// Tags: matrix

// O(M * N) O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // check leftmost column
        bool setFirstColumn = false;
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                setFirstColumn = true;
                break;
            }
        }
        bool setFirstRow = false;
        for (size_t i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                setFirstRow = true;
                break;
            }
        }
        for (size_t i = 1; i < matrix.size(); ++i)
            for (size_t j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (size_t i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                vector<int> temp(matrix[0].size());
                matrix[i] = temp;
            }
        }
        for (size_t i = 1; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                for (size_t j = 1; j < matrix.size(); ++j)
                    matrix[j][i] = 0;
            }
        }
        if (setFirstColumn)
            for (size_t i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        if (setFirstRow)
            for (size_t i = 0; i < matrix[0].size(); ++i) matrix[0][i] = 0;
    }
};
