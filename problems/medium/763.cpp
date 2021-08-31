// Number: 763
// Name: Partition Labels
// Tags: two pointers, hash table

// O(N) + O(K), O(N)
class Solution_0 {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> dict;
        // O(N)
        for (int i = 0; i < s.size(); ++i) {
            if (dict.find(s[i]) != dict.end())
                dict[s[i]].second = i;
            else dict[s[i]] = make_pair(i, i);
        }
        // O(K)
        vector<pair<int, int>> data;
        for (const auto& x : dict)
            data.push_back(x.second);
        // O(logK)
        sort(data.begin(), data.end(), 
             [](const auto& lhs, const auto& rhs){
                 return lhs.first <= rhs.first;
             });
        vector<int> answer;
        int curStart = -1;
        int curEnd = -1;
        // O(K)
        for (int i = 0; i < data.size(); ++i) {
            int d_start = data[i].first;
            int d_end = data[i].second;
            if (curStart == -1) {
                curStart = d_start;
                curEnd = d_end;
            } else {
                if (d_start < curEnd) {
                    if (d_end > curEnd) curEnd = d_end;
                } else {
                    answer.push_back(curEnd - curStart + 1);
                    curStart = d_start;
                    curEnd = d_end;
                }
            }
            if (i == data.size() - 1)
                answer.push_back(curEnd - curStart + 1);
        }
        return answer;
    }
};

// O(N), O(1)
class Solution_1 {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> data;
        // O(N)
        for (int i = 0; i < s.size(); ++i)
            data[s[i]] = i;
        vector<int> answer;
        int curStart = -1;
        int curEnd = -1;
        // O(K)
        for (int i = 0; i < s.size(); ++i) {
            int d_end = data[s[i]];
            if (curStart == -1) {
                curStart = i;
                curEnd = d_end;
            } else {
                if (i <= curEnd) {
                    if (d_end > curEnd) curEnd = d_end;
                } else {
                    answer.push_back(curEnd - curStart + 1);
                    curStart = i;
                    curEnd = d_end;
                }
            }
            if (i == s.size() - 1) {
                answer.push_back(curEnd - curStart + 1);
            }
        }
        return answer;
    }
};
