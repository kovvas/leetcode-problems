// Number: 926
// Name: Flip String to Monotone Increasing
// Tags: string, DP

// O(N), O(N)
// need to clean it a little bit
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int totalOnes = 0;
        int totalZeroes = 0;
        int temp = 0;
        size_t realStart = 0;
        for (; realStart < s.size(); ++realStart) {
            if (s[realStart] == '1') break;
        }
        
        if (realStart == s.size()) return 0;
        for (size_t i = realStart; i < s.size(); ++i) {
            if (s[i] == '1') totalOnes++;
            else totalZeroes++;
        }
        if (totalZeroes == 0 || totalOnes == 0) return 0;
        int answer = min(totalZeroes, totalOnes);
        bool lastZero = true;
        vector<int> data(2);
        for (size_t i = realStart; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (lastZero) {
                    answer = min(answer, totalZeroes - data[1] + data[0] + temp);
                    totalZeroes -= data[1];
                    temp += data[0];
                    data = {1, 0};
                    lastZero = false;
                }
                else data[0]++;
            }
            else {
                data[1]++;
                if (!lastZero) lastZero = true;
            }
        }
        return answer;
    }
};