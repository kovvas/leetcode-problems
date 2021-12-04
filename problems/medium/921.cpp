// Number: 921
// Name: Minimum Add to Make Parentheses Valid
// Tags: stack

// O(N), O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> d_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                d_stack.push(s[i]);
            else if (!d_stack.empty() && d_stack.top() == '(')
                d_stack.pop();
            else d_stack.push(s[i]); 
        }
        return d_stack.size();
    }
};

// O(N), O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> d_stack;
        int opened = 0;
        int closed = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                opened++;
            else if (opened > 0) opened--;
            else closed++;
        }
        return opened + closed;
    }
};
