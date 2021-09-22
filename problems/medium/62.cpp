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