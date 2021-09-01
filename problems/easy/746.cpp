// Number: 746
// Name: Min Cost Climbing Stairs
// Tags: DP

// O(N), O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> sums(cost.size() + 1, 0);
        sums[0] = 0;
        sums[1] = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            sums[i] = min(cost[i - 1] + sums[i - 1], cost[i - 2] + sums[i - 2]);
        }
        return sums[cost.size()];
    }
};
