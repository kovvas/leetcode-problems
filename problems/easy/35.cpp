// Number: 35
// Name: Search Insert Position
// Tags: array, binary search

int searchInsert(vector<int>& nums, int target) {
    int lhs = 0;
    int rhs = nums.size() - 1;
    while (lhs <= rhs) {
        int mid = lhs + (rhs - lhs) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) lhs = mid + 1;
        else rhs = mid - 1;
    }
    return lhs;
}

