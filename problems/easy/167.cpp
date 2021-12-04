// Number: 167
// Name: Two Sum II - Input Array Is Sorted
// Tags: two poiner

// O(N) O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        answer.reserve(2);
        size_t lhs = 0;
        size_t rhs = numbers.size() - 1;
        while (lhs < rhs) {
            int curSum = numbers[lhs] + numbers[rhs];
            if (curSum == target) {
                answer.push_back(lhs + 1);
                answer.push_back(rhs + 1);
                return answer;
            }
            else if (curSum < target)
                lhs++;
            else rhs--;
        }
        return answer;
    }
};
