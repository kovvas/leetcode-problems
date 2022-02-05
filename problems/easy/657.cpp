// Number: 657
// Name: Robot Return to Origin
// Tags: math

// O(N) O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int x_dif = 0;
        int y_dif = 0;
        for (const auto& x : moves) {
            if (x == 'R') x_dif++;
            else if (x == 'L') x_dif--;
            else if (x == 'U') y_dif++;
            else if (x == 'D') y_dif--;
        }
        if (x_dif == 0 && y_dif == 0) return true;
        return false;
    }
};
