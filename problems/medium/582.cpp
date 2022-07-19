// Number: 582
// Name: Kill Process
// Tags: BFS

// O(N) O(N)
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> p_to_id;
        for (int i = 0; i < ppid.size(); ++i) {
            p_to_id[ppid[i]].push_back(pid[i]);
        }
        vector<int> answer {kill};
        queue<int> to_kill;
        to_kill.push(kill);
        while (!to_kill.empty()) {
            int curKill = to_kill.front();
            to_kill.pop();
            if (p_to_id.find(curKill) != p_to_id.end()) {
                answer.insert(answer.end(), p_to_id[curKill].begin(), p_to_id[curKill].end());
                for (int p : p_to_id[curKill])
                    to_kill.push(p);
            }
        }
        return answer;
    }
};
