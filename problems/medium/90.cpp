// Number: 90
// Subsets II
// Tags: BFS, Backtracking

// O(nlogn + N*2^N)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {{}};
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer = {{nums[0]}, {}};
        vector<vector<int>> last_modified = {{nums[0]}};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                for (auto& s : last_modified) {
                    s.push_back(nums[i]);
                    answer.push_back(s);
                }
            } else {
                last_modified = {};
                for (auto s : answer) {
                    s.push_back(nums[i]);
                    last_modified.push_back(s);
                }
                answer.insert(answer.end(), last_modified.begin(), last_modified.end());
            }
        }
        return answer;
    }
};
