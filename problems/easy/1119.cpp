// Number: 1119
// Name: Remove Vowels from a String
// Tags: string

// O(N), O(1)
class Solution {
public:
    string removeVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int result_size = s.size();
        for (size_t i = 0; i < s.size(); ++i) {
            if (vowels.count(s[i]) > 0) {
                s[i] = 'a';
                result_size--;
            }
        }
        string answer(result_size, ' ');
        size_t pos = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != 'a') answer[pos++] = s[i];
        }
        return answer;
    }
};
