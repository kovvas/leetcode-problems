// Number: 560
// Name: Subarray Sum Equals K
// Tags: cumsum

// O(N) O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefSums;
        int curSum = 0;
        int answer = 0;
        for (const auto& x : nums) {
            curSum += x;
            if (curSum == k)
                answer++;
            if (prefSums.find(curSum - k) != prefSums.end())
                answer += prefSums[curSum - k];
            prefSums[curSum]++;
        }
        return answer;
    }
};
