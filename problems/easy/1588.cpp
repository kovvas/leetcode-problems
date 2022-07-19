// Number: 1588
// Name: Sum of All Odd Length Subarrays
// Tags: math

// O(N) O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int answer = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int part = (i + 1) * (arr.size() - i);
            if (arr.size() % 2 == 0)
                answer += part / 2 * arr[i];
            else answer += (part + 1) / 2 * arr[i];
        }
        return answer;
    }
};
