// Number: 161
// Name: One Edit Distance
// Tags: two pointers

// O(N), O(1)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (s.empty() && t.empty()) return false;
        if (s_size - t_size > 1 || t_size - s_size > 1) return false;
        if (t.size() == s.size()) {
            // check for 1 diff char
            bool isDiff = false;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != t[i]) {
                    if (isDiff) return false;
                    isDiff = true;
                }
            }
            if (!isDiff) return false;
        } else if (s.size() < t.size()) {
            // check for 1 missing char
            bool isDiff = false;
            for (int i = 0, j = 0; i < s.size();) {
                if (s[i] != t[j]) {
                    j++;
                    if (isDiff) return false;
                    isDiff = true;
                } else {
                    i++;
                    j++;
                }
            }
        } else {
            // check for 1 extra char
            bool isDiff = false;
            for (int i = 0, j = 0; i < s.size();) {
                if (s[i] != t[j]) {
                    i++;
                    if (isDiff) return false;
                    isDiff = true;
                } else {
                    i++;
                    j++;
                }
            }
        }
        return true;
    }
};
