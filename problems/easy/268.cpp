// Number: 268
// Name: Missing Number
// Tags: Math, bit manipulation

// math, O(N) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        for (const auto& x : nums)
            totalSum -= x;
        return totalSum;
    }
};

// bit manipulation O(N) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int curState = nums.size();
        for (const auto& x : nums)
            curState ^= x;
        for (int i = 0; i < nums.size(); ++i)
            curState ^= i;
        return curState;
    }
};
