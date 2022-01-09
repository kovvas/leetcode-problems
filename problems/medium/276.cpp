// Number: 276
// Name: Paint Fence
// Tags: dynamic programming

// brute force
class Solution_0 {
public:
    int helper(int n, int k, int prevColor, int whatWasBefore) {
        if (n == 0) return 1;
        int combinations = 0;
        for (int i = 1; i <= k; ++i) {
            if (i != prevColor) combinations += helper(n - 1, k, i, 0);
            else if (whatWasBefore != i) combinations += helper(n - 1, k, i, i);
        }
        return combinations;
    }
    
    int numWays(int n, int k) {
        return helper(n, k, 0, 0);
    }
};

// DP O(N) O(1)
class Solution {
public:
    int numWays(int n, int k) {
        int first = k;
        int second = k * k;
        if (n == 1) return first;
        if (n == 2) return second;
        for (int i = 2; i < n; ++i) {
            int temp = (k - 1) * (second + first);
            first = second;
            second = temp;
        }
        return second;
    }
};

