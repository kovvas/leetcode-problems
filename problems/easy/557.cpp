// Number: 557
// Name: Reverse Words in a String III
// Tags: string

// O(N), O(1)
class Solution {
public:
    void reverseWord(string& s, int lhs, int rhs) {
        while (lhs < rhs)
            swap(s[lhs++], s[rhs--]);
    }
    
    string reverseWords(string s) {
        size_t lhs = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverseWord(s, lhs, i - 1);
                lhs = i + 1;
            }
        }
        if (lhs != s.size())
            reverseWord(s, lhs, s.size() - 1);
        return s;
    }
};
