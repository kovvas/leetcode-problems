// Number: 1152
// Name: Analyze User Website Visit Pattern
// Tags: hashmap

// O(N) O(N)
class Solution {
public:
    string createPattern(const vector<string>& i_vec) {
        string answer = i_vec[0];
        answer += "$";
        answer += i_vec[1];
        answer += "%";
        answer += i_vec[2];
        return answer;
    }
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, int> data;
        unordered_map<string, map<int, string>> users;
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            users[username[i]][timestamp[i]] = website[i];
        }
        for (const auto& x : users) {
            if (x.second.size() < 3) continue;
            unordered_set<string> userData;
            for (auto it1 = begin(x.second); it1 != end(x.second); ++it1) {
                for (auto it2 = next(it1); it2 != end(x.second); ++it2) {
                    for (auto it3 = next(it2); it3 != end(x.second); ++it3) {
                        vector<string> curPattern = {it1->second, it2->second, it3->second};
                        string pattern = createPattern(curPattern);
                        userData.insert(pattern);
                    }
                }
            }
            for (const auto& x : userData) data[x]++;
        }
        int maxVisited = 0;
        string maxPattern;
        for (const auto& x : data) {
            if (maxVisited < x.second) {
                maxVisited = x.second;
                maxPattern = x.first;
            } else if (maxVisited == x.second) {
                maxPattern = min(maxPattern, x.first);
            }
        }
        auto sep1 = maxPattern.find("$");
        auto sep2 = maxPattern.find("%");
        return { maxPattern.substr(0, sep1), maxPattern.substr(sep1 + 1, sep2 - sep1 - 1), maxPattern.substr(sep2 + 1) };
    }
};
