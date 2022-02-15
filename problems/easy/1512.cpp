// Number: 1512
// Name: Number of Good Pairs
// Tags: array

// O(N) O(N)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> data;
        for (const auto& x : nums) data[x]++;
        int answer = 0;
        for (const auto& x : data) {
            if (x.second == 1) continue;
            if (x.second == 2) answer += 1;
            else answer += (x.second - 1) * x.second / 2;
        }
        return answer;
    }
};
