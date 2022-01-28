// Number: 735
// Name: Asteroid Collision
// Tags: stack

// O(N) O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> data;
        for (const auto& x : asteroids) {
            if (x >= 0) data.push(x);
            else if (data.empty() || data.top() < 0)
                data.push(x);
            else {
                while (!data.empty() && data.top() > 0) {
                    if (data.top() == abs(x)) {
                        data.pop();
                        break;
                    } else if (data.top() > abs(x)) break;
                    else {
                        data.pop();
                        if (data.empty() || data.top() < 0) {
                            data.push(x);
                            break;
                        }
                    }
                }
            }
        }
        if (data.empty()) return {};
        vector<int> answer;
        while (!data.empty()) {
            answer.push_back(data.top());
            data.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
