// Number: 62
// Name: Unique Paths
// Tags: recursive, DP

// recursive
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

// DP
// O(N*M), O(N*M)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int data[m][n];
        for (int i = 0; i < n; ++i) {
            data[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            data[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                data[i][j] = data[i][j - 1] + data[i - 1][j];
            }
        }
        return data[m - 1][n - 1];
    }
};
