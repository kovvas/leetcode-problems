// Number: 41
// Name: First Missing Positive
// Tags: cyclic sort

// O(N) O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int answer = 0;
        while (answer < nums.size()) {
            int cur = nums[answer];
            if (cur > 0 && cur <= nums.size() && cur != nums[cur - 1])
                swap(nums[answer], nums[cur - 1]);
            else answer++;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
