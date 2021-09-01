// Number: 973
// Name: K Closest Points to Origin
// Tags: heap, sort

class Comp {
    public:
        int operator()(const vector<int>& p1, const vector<int>& p2) {
            int p1_dist_sq = p1[0]*p1[0] + p1[1]*p1[1];
            int p2_dist_sq = p2[0]*p2[0] + p2[1]*p2[1];
            return p1_dist_sq > p2_dist_sq;
        }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> answer;
    priority_queue<vector<int>, vector<vector<int>>, Comp> minHeap;
    for (int i = 0; i < points.size(); ++i) {
        minHeap.push(points[i]);
        if (minHeap.size() > points.size() - K) {
            answer.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    return answer;
}

// O(N) + O(NlogN)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), 
            [](const auto& lhs, const auto& rhs) {
                return (lhs[0]*lhs[0] + lhs[1]*lhs[1]) <= (rhs[0]*rhs[0] + rhs[1]*rhs[1]);
            });
        vector<vector<int>> answer(points.begin(), points.begin() + k);
        return answer;
    }
};
