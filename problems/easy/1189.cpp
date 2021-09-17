// Number: 1189
// Name: Maximum Number of Balloons
// Tags: string

// O(N + M)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> data;
        data['b'] = 0;
        data['a'] = 0;
        data['n'] = 0;
        data['l'] = 0;
        data['o'] = 0;
        unordered_set<char> single_chars = {'b', 'a', 'n'};
        unordered_set<char> double_chars = {'l', 'o'};
        for (const auto& x : text) {
            if (single_chars.count(x) > 0 || double_chars.count(x) > 0)
                data[x]++;
        }
        int answer = INT_MAX;
        for (const auto& x : single_chars) {
            answer = min(answer, data[x]);
        }
        for (const auto& x : double_chars) {
            answer = min(answer, data[x] / 2);
        }
        return answer;
    }
};