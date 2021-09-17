// Number: 392
// Name: Is Subsequence
// Tags: string, trie, binary search

bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    if (t.size() < s.size()) return false;
    for (int i = 0, j = 0; i < s.size(), j < t.size();) {
        if (t.size() - j < s.size() - i) return false;
        if (s[i] == t[j]) {
            i++;
            j++;
            if (i == s.size()) return true;
        } else {
            j++;
        }
    }
    return false;
}

bool isSubsequence(string s, string t) {
    unordered_map<char, vector<int>> data;
    for (int i = 0; i < t.size(); ++i) {
        data[t[i]].push_back(i);
    }
    int curMatchedIndex = -1;
    for (const auto& x : s) {
        if (data.find(x) == data.end()) return false;

        bool isMatched = false;
        for (const auto& matchedIndex : data[x]) {
            if (curMatchedIndex < matchedIndex) {
                curMatchedIndex = matchedIndex;
                isMatched = true;
                break;
            }
        }

        if (!isMatched) return false;
    }
    return true;
}