// Number: 159
// Name: Longest Substring with At Most Two Distinct Characters
// Tags: string

// O(N), O(K) , where K = 2
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int K = 2;
        int curDistinct = 0;
        int answer = 0;
        int curLen = 0;
        int lhs = 0;
        unordered_map<char, int> curChars;
        unordered_set<char> curCharsSet;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (curCharsSet.count(c) == 0) {
                // new char
                if (curCharsSet.size() >= K) {
                    curChars[c] = 1;
                    curCharsSet.insert(c);
                    while (lhs < i) {
                        curChars[s[lhs]]--;
                        if (curChars[s[lhs]] == 0) {
                            curCharsSet.erase(s[lhs]);
                            lhs++;
                            break;
                        }
                        lhs++;
                    }
                } else {
                    // we have space
                    curCharsSet.insert(c);
                    curChars[c]++;
                }
            } else {
                curChars[c]++;
            }
            answer = max(answer, i - lhs + 1);
        }
        return answer;
    }
};
