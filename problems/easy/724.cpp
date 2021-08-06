// Number: 724
// Name: Find Pivot Index
// Tags: Prefix Sum

// using extra array
class Solution_1 {
public:
int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        size_t n = nums.size();
        vector<int> sums(n, 0);
        sums[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
            sums[i] = sums[i + 1] + nums[i + 1];
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (curSum == sums[i]) return i;
            curSum += nums[i];
        }
        return -1;
    }
};

// using prefix sum
class Solution_2 {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int sums = 0, left_sums = 0;
        for (int i = 0; i < nums.size(); ++i)
            sums += nums[i];
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sums == sums - left_sums - nums[i]) return i;
            left_sums += nums[i];
        }
        return -1;
    }
};

