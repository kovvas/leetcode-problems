// Number: 670
// Name: Maximum Swap
// Tags: stack, two pointers

// O(N), O(N)
class Solution {
public:
    int maximumSwap(int num) {
        stack<pair<int, int>> max_stack;
        string s = to_string(num);
        if (s.size() == 1) return num;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (max_stack.empty()) 
                max_stack.push(make_pair(s[i], i));
            else if (max_stack.top().first == s[i])
                max_stack.push(make_pair(s[i], max_stack.top().second));
            else if (max_stack.top().first < s[i])
                max_stack.push(make_pair(s[i], i));
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            auto curMax = max_stack.top();
            int curLeft = s[i];
            if (curLeft < curMax.first) {
                s[i] = curMax.first;
                s[curMax.second] = curLeft;
                int answer = stoi(s);
                return answer;
            }
            if (curLeft == curMax.first)
                max_stack.pop();
        }
        return num;
    }
};