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

// a bit cleaner
class Solution {
public:
    int compress(vector<char>& chars) {
        char curChar = chars[0];
        int curCharCnt = 1;
        size_t ptr = 0;
        for (size_t i = 1; i < chars.size(); ++i) {
            if (chars[i] == curChar)
                curCharCnt++;
            else {
                chars[ptr++] = curChar;
                curChar = chars[i];
                if (curCharCnt > 1) {
                    string num = to_string(curCharCnt);
                    curCharCnt = 1;
                    for (const auto& c : num)
                        chars[ptr++] = c;
                }
            }
        }
        chars[ptr++] = curChar;
        if (curCharCnt > 1) {
            string num = to_string(curCharCnt);
            curCharCnt = 1;
            for (const auto& c : num)
                chars[ptr++] = c;
        }
        chars.resize(ptr);
        return chars.size();
    }
};
