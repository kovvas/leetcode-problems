// Number: 1893
// Name: Check if All the Integers in a Range Are Covered
// Tags: slices

// time O(nlogn) space O(1)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](const auto& lhs, const auto& rhs) {
           return lhs[0] < rhs[0]; 
        });
        for (const auto& x : ranges) {
            if (x[1] < left || x[0] > right) continue;
            if (left <= x[1] && left >= x[0]) {
                if (right <= x[1]) return true;
                left = x[1] + 1;
            }
        }
        return false;
    }
};

