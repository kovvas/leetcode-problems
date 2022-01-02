// Number: 150
// Name: Evaluate Reverse Polish Notation
// Tags: stack

// O(N) O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int answer = 0;
        stack<int> data;
        for (size_t i = 0; i < tokens.size(); ++i) {
            string curToken = tokens[i];
            if (curToken == "+") {
                int a = data.top();
                data.pop();
                int b = data.top();
                data.pop();
                data.push(b + a);
            } else if (curToken == "-") {
                int a = data.top();
                data.pop();
                int b = data.top();
                data.pop();
                data.push(b - a);
            } else if (curToken == "/") {
                int a = data.top();
                data.pop();
                int b = data.top();
                data.pop();
                data.push(b / a);
            } else if (curToken == "*") {
                int a = data.top();
                data.pop();
                int b = data.top();
                data.pop();
                data.push(b * a);
            } else data.push(stoi(curToken));
        }
        return data.top();
    }
};
