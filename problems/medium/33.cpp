// Number: 33
// Name: Search in Rotated Sorted Array
// Tags: binary search

// O(logN) O(1)
class Solution {
public:
    int binSearch(const vector<int>& nums, int lhs, int rhs, int target) {
        while (lhs <= rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) rhs = mid - 1;
            else lhs = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        if (n == 0) {
            if (nums[0] == target) return 0;
            return -1;
        }
        if (nums[0] < nums[n])
            return binSearch(nums, 0, n, target);
        
        int pivot = 0;
        int lhs = 0;
        int rhs = n;
        while (lhs <= rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[mid + 1]) {
                pivot = mid + 1;
                break;
            }
            else {
                if (nums[mid] < nums[lhs])
                    rhs = mid - 1;
                else
                    lhs = mid + 1;
            }
        }
        
        if (nums[pivot] == target) return pivot;
        if (target < nums[0])
            return binSearch(nums, pivot, n, target);
        return binSearch(nums, 0, pivot, target);
    }
};

// O(logN) O(1) one bin search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        while (lhs <= rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[lhs]) {
                if (target < nums[mid] && target >= nums[lhs])
                    rhs = mid - 1;
                else lhs = mid + 1;
            } else {
                if (target <= nums[rhs] && target > nums[mid])
                    lhs = mid + 1;
                else rhs = mid - 1;
            }
        }
        return -1;
    }
};

