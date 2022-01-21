// Number: 287
// Name: Find the Duplicate Number
// Tags: binary search

// O(nlogn) O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lhs = 1;
        int rhs = nums.size() - 1;
        int answer = -1;
        while (lhs <= rhs) {
            int cur = lhs + (rhs - lhs) / 2;
            int count = 0;
            for (int i : nums)
                if (i <= cur) count++;
            if (count > cur) {
                answer = cur;
                rhs = cur - 1;
            } else lhs = cur + 1;
        }
        return answer;
    }
};