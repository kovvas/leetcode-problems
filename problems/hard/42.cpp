// Number: 42
// Name: Trapping Rain Water
// Tags: Array

// O(N) O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int totalSum = 0;
        int lhs = 0;
        int lhs_index = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] != 0) {
                if (lhs == 0) {
                    lhs = height[i];
                    lhs_index = i;
                }
                else if (height[i] >= lhs) {
                    totalSum += lhs * (i - lhs_index);
                    lhs = height[i];
                    lhs_index = i;
                }
            }
        }
        totalSum += lhs;
        lhs = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            if (height[i] != 0) {
                if (lhs == 0) {
                    lhs = height[i];
                    lhs_index = i;
                }
                else if (height[i] > lhs) {
                    totalSum += lhs * (lhs_index - i);
                    lhs = height[i];
                    lhs_index = i;
                }
            }
        }
        for (const auto& x : height) {
            if (x != 0) totalSum -= x;
        }
        return totalSum;
    }
};
