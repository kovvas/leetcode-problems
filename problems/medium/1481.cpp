// Number: 1481
// Name: Least Number of Unique Integers after K Removals
// Tags: priority queue

// O(N + NlogN), O(K)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> data;
        for (const auto& x : arr) {
            data[x]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& x : data) {
            pq.push(x.second);
        }
        while (k > 0) {
            int curTop = pq.top();
            if (curTop - k <= 0)
                pq.pop();
            k -= curTop;
        }
        return pq.size();
    }
};
