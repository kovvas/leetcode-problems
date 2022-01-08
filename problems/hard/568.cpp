// Number: 568
// Name: Maximum Vacation Days
// Tags: DP

// O(nˆk) O(k)
class Solution {
public:
    void helper(int w, vector<vector<int>>& f,
                vector<vector<int>>& d,
                unordered_set<int>& vac_days,
                int cur_vac,
                int cur_city) {
        cur_vac += d[cur_city][w];
        if (w == d[0].size() - 1) {
            vac_days.insert(cur_vac);
            return;
        }
        helper(w + 1, f, d, vac_days, cur_vac, cur_city);
        for (size_t i = 0; i < f.size(); ++i) {
            if (f[cur_city][i] == 1)
                helper(w + 1, f, d, vac_days, cur_vac, i);
        }
    }
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        unordered_set<int> vac_days;
        helper(0, flights, days, vac_days, 0, 0);
        for (size_t i = 0; i < flights.size(); ++i) {
            if (flights[0][i] == 1)
                helper(0, flights, days, vac_days, 0, i);
        }
        int answer = 0;
        for (const auto& x : vac_days) {
            answer = max(answer, x);
        }
        return answer;
    }
};

