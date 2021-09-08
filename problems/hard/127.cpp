// Number: 127
// Name: Word Ladder
// Tags: BFS

class Solution {
public:
    bool isDiffByOne(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        bool wasDiff = false;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (wasDiff) return false;
                else wasDiff = true;
            }
        }
        return true;
    }
    
    void addMutationToQueue(string& s, queue<string>& q, unordered_set<string>& set) {
        for (int i = 0; i < s.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                char temp = s[i];
                s[i] = c;
                if (set.find(s) != set.end()) {
                    q.push(s);
                    set.erase(s);
                }
                s[i] = temp;
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        queue<string> q;
        unordered_set<string> data;
        for (const auto& x : wordList)
            data.insert(x);
        q.push(endWord);
        int answer = 1;
        while (!q.empty()) {
            int toProcess = q.size();
            for (int i = 0; i < toProcess; ++i) {
                string curWord = q.front();
                q.pop();
                data.erase(curWord);
                if (isDiffByOne(curWord, beginWord)) return ++answer;
                addMutationToQueue(curWord, q, data);
            }
            answer++;
        }
        return 0;
    }
};
