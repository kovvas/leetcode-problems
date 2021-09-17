// Number: 704
// Name: Binary Search
// Tags: binary search

// O(logN) O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        while (lhs <= rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) rhs = mid - 1;
            else lhs = mid + 1;
        }
        return -1;
    }
};
