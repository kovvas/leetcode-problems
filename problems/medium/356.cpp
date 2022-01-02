// Number: 356
// Name: Line Reflection
// Tags: Math

// time O(N) space O(N)
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if (points.size() == 1) return true;
        if (points.size() == 0) return false;
        double lhs = points[0][0];
        double rhs = points[0][0];
        unordered_map<double, unordered_set<int>> data;
        for (const auto& x : points) {
            if (x[0] > rhs) rhs = x[0];
            if (x[0] < lhs) lhs = x[0];
            data[x[0]].insert(x[1]);
        }
        double X = (lhs + rhs) / 2;
        for (const auto& x : points) {
            if (x[0] == X) continue;
            double mirrorX = 2 * X - x[0];
            if (data.find(mirrorX) != data.end()) {
                if (data[mirrorX].count(x[1]) == 0) return false;
            } else return false;
        }
        return true;
    }
};
