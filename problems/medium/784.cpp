// Number: 784
// Name: Letter Case Permutation
// Tags: BFS

// O(N*2^N) O(1)
class Solution {
public:
    string changeCase(string s, size_t pos) {
        if (isupper(s[pos])) {
            s[pos] = tolower(s[pos]);
        } else s[pos] = toupper(s[pos]);
        return s;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> answer;
        for (int i = 0; i < s.size(); ++i) {
            if (answer.empty()) {
                if (!isdigit(s[i])) {
                    answer.push_back(s);
                    answer.push_back(changeCase(s, i));
                }
            } else {
                if (!isdigit(s[i])) {
                    vector<string> new_strs;
                    for (auto ans : answer) {
                        new_strs.push_back(changeCase(ans, i));
                    }
                    answer.insert(answer.end(), new_strs.begin(), new_strs.end());
                }
            }
        }
        if (answer.empty()) answer.push_back(s);
        return answer;
    }
};
