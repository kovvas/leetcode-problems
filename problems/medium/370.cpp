// Number: 370
// Name: Range Addition
// Tags: cumulitive sum

// O(N + K) O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> data(length);
        for (const auto& update : updates) {
            data[update[1]] += update[2];
            if (update[0] != 0) data[update[0] - 1] -= update[2];
        }
        int prev = data.back();
        for (int i = data.size() - 2; i >= 0; --i) {
            data[i] += prev;
            prev = data[i];
        }
        return data;
    }
};
