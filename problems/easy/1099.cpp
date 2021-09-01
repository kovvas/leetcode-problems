// Number: 1099
// Name: Two Sum Less Than K
// Tags: two pointers, sorting

// O(NlogN), O(logN)
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lhs = 0;
        int rhs = nums.size() - 1;
        int answer = -1;
        while (lhs != rhs) {
            int sum = nums[lhs] + nums[rhs];
            if (sum >= k) {
                rhs--;
            } else {
                answer = max(answer, sum);
                lhs++;
            }
        }
        return answer;
    }
};
