// Number: 436
// Name: Find Right Interval
// Tags: sort, binary search

// O(N*logN), O(N)
class Solution {
public:
    int findRight(const vector<vector<int>>& intervals, int curEnd, const unordered_map<int, int>& indexes) {
        int lhs = 0;
        int rhs = intervals.size() - 1;
        while (lhs < rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (intervals[mid][0] < curEnd) {
                lhs = mid + 1;
            } else rhs = mid;
        }
        if (intervals[lhs][0] >= curEnd)
            return indexes.at(intervals[lhs][0]);
        return -1;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int, int> indexes;
        vector<int> answer(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i)
            indexes[intervals[i][0]] = i;
        sort(intervals.begin(), intervals.end(), [](
            const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        });
        for (int i = 0; i < intervals.size(); ++i) {
            int curEnd = intervals[i][1];
            int ans = findRight(intervals, curEnd, indexes);
            answer[indexes[intervals[i][0]]] = ans;
        }
        return answer;
    }
};

