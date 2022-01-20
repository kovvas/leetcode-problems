// Number: 268
// Name: Missing Number
// Tags: Math, bit manipulation

// sort, O(N) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < nums.size() && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
            else i++;
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

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
