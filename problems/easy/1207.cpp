// Number: 1207
// Name: Unique Number of Occurrences
// Tags: hashing

// O(N) O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        unordered_set<int> unique_counts;
        for (const auto& x : arr)
            counts[x]++;
        for (const auto& x : counts) {
            if (unique_counts.count(x.second) != 0) return false;
            unique_counts.insert(x.second);
        }
        return true;
    }
};
