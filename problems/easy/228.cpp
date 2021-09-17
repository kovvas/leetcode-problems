// Number: 228
// Name: Summary Ranges
// Tags: array

class Solution {
public:
    string makeRange(int a, int b) {
        string range = "";
        if (a == b)
            return to_string(a);
        range = to_string(a) + "->" + to_string(b);
        return range;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int lhs = 0;
        int rhs = 0;
        vector<string> answer;
        if (nums.size() == 1) {
            answer.push_back(makeRange(nums[0], nums[0]));
            return answer;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) rhs++;
            else {
                answer.push_back(makeRange(nums[lhs], nums[rhs]));
                lhs = i;
                rhs = i;
            }
        }
        answer.push_back(makeRange(nums[lhs], nums[rhs]));
        return answer;
    }
};
