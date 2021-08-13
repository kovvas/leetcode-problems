// Number: 152
// Name: Maximum Product Subarray
// Tags: DP, array

// brure force O(N^2)
class Solution_1 {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int curProd = 1;
            for (int j = i; j < nums.size(); ++j) {
                curProd *= nums[j];
                if (curProd > maxProd) maxProd = curProd;
            }
        }
        return maxProd;
    }
};

