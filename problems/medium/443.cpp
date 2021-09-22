// Number: 443
// Name: String Compression
// Tags: array

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        if (chars.size() == 1) return 1;
        int lhs = 0;
        int rhs = 0;
        for (; rhs < chars.size();) {
            chars[lhs] = chars[rhs];
            int cnt = 0;
            while (rhs < chars.size() && chars[lhs] == chars[rhs]) {
                rhs++;
                cnt++;
            }
            lhs++;
            if (cnt > 1) {
                string temp = to_string(cnt);
                for (const auto& x : temp)
                    chars[lhs++] = x;
            }
            cnt = 0;
        }
        chars.resize(lhs);
        return chars.size();
    }
};
