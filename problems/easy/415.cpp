// Number: 415
// Name: Add Strings
// Tags: Math, string

// O(N)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string answer = "";
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int extra = 0;
        while (n1 >= 0 || n2 >= 0 || extra) {
            int sum = 0;
            if (n1 >= 0) sum += num1[n1--] - '0';
            if (n2 >= 0) sum += num2[n2--] - '0';
            sum += extra;
            answer += to_string(sum % 10);
            extra = sum / 10;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
