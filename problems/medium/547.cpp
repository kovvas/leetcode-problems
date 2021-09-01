// Number: 547
// Name: Number of Provinces
// Tags: BFS, DFS

// O(n^2), O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = 0;
        int n = isConnected.size();
        vector<int> wasProcessed(n, 0);
        queue<int> toProcess;
        for (int i = 0; i < n; ++i) {
            if (wasProcessed[i] != 0) continue;
            toProcess.push(i);
            while (!toProcess.empty()) {
                int curCity = toProcess.front();
                wasProcessed[curCity] = 1;
                toProcess.pop();
                for (int j = 0; j < n; ++j) {
                    if (isConnected[curCity][j] == 1 && wasProcessed[j] == 0)
                        toProcess.push(j);
                }
            }
            answer++;
        }
        return answer;
    }
};
