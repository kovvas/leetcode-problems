// Number: 502
// Name: IPO
// Tags: head, set, greedy

// O(N*logN), O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multiset<pair<int, int>> expensive;
        priority_queue<int> affordable;
        for (int i = 0; i < profits.size(); ++i) {
            if (profits[i] > 0) {
                if (capital[i] <= w)
                    affordable.push(profits[i]);
                else expensive.emplace(make_pair(capital[i], profits[i]));
            }
        }
        while (k-- && !affordable.empty()) {
            w += affordable.top();
            affordable.pop();
            for (auto it = expensive.begin(); !expensive.empty() && it->first <= w; it = expensive.erase(it)) {
                affordable.push(it->second);
            }
        }
        return w;
    }
};
