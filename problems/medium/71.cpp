// Number: 71
// Name: Simplift Path
// Tags: stack, string

// O(N) O(N)
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return path;
        stack<string> data;
        data.push("/");
        string curWord = "";
        for (size_t i = 1; i < path.size(); ++i) {
            if (path[i] == '/' && curWord == "")
                continue;
            if (path[i] == '/') {
                if (curWord == "..") {
                    if (data.size() != 1) {
                        data.pop();
                        data.pop();
                    }
                } else if (curWord != ".") {
                    data.push(curWord);
                    data.push("/");
                }
                curWord = "";
            } else curWord += path[i];
        }
        if (curWord == "..") {
            if (data.size() != 1) {
                data.pop();
                data.pop();
            }
        } else if (curWord != "." && curWord != "")
            data.push(curWord);
        if (data.size() != 1 && data.top() == "/") data.pop();
        stack<string> temp;
        while (!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        string answer;
        while (!temp.empty()) {
            answer += temp.top();
            temp.pop();
        }
        return answer;
    }
};
