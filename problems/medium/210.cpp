// Number: 210
// Name: Course Schedule II
// Tags: hash map, topological sort

// hashmap, O(N^2) O(N^2)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> cTP;
        vector<int> answer;
        queue<int> toTake;
        for (const auto& x : prerequisites)
                cTP[x[0]].insert(x[1]);
        for (int i = 0; i < numCourses; ++i)
            if (cTP.find(i) == cTP.end())
                toTake.push(i);
        if (toTake.empty()) return {};
        while (!toTake.empty()) {
            int curCourse = toTake.front();
            answer.push_back(curCourse);
            if (answer.size() == numCourses) return answer;
            toTake.pop();
            for (auto& x : cTP) {
                if (x.second.count(curCourse) == 1)
                    x.second.erase(curCourse);
            }
            for (auto it = cTP.begin(); it != cTP.end();) {
                if (it->second.empty()) {
                    toTake.push(it->first);
                    it = cTP.erase(it);
                }
                else it++;
            }
        }
        if (answer.size() != numCourses) return {};
        return answer;
    }
};

//