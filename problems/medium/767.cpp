// Number: 767
// Name: Reorganize String
// Tags: String, Greedy

// O(nlong) O(n)
class Solution {
public:
    class Comparator {
    public:
        bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) {
            return lhs.second <= rhs.second;
        }
    };
    
    string reorganizeString(string s) {
        unordered_map<char, int> dict;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> data;
        for (const auto& x : s) dict[x]++;
        for (const auto& x : dict) data.push(x);
        if (data.size() == 1) return "";
        string answer = "";
        
        while (data.size() > 1) {
            auto max = data.top();
            data.pop();
            auto small = data.top();
            data.pop();
            if (answer.back() != max.first) {
                answer += max.first;
                answer += small.first;
            } else {
                answer += small.first;
                answer += max.first;
            }
            max.second--;
            small.second--;
            if (max.second > 0)
                data.push(max);
            if (small.second > 0)
                data.push(small);
        }
        
        if (!data.empty() && data.top().second > 1) return "";
        if (!data.empty() && data.top().second == 1)
            answer += data.top().first;
        
        return answer;
    }
};
