// educativeio problem
// https://www.educative.io/courses/grokking-the-coding-interview/q2LA7G0ANX0
// tags: cyclic sort

// O(N) O(N)
class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    unordered_set<int> extra_numbers;
    int answer = 0;
    while (answer < nums.size()) {
        int cur = nums[answer];
        if (cur > 0 && cur <= nums.size() && cur != nums[cur - 1])
            swap(nums[answer], nums[cur - 1]);
        else answer++;
        if (cur > nums.size()) extra_numbers.insert(cur);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
          missingNumbers.push_back(i + 1);
          if (missingNumbers.size() == k) return missingNumbers;
        }
    }
    int n = nums.size() + 1;
    while (missingNumbers.size() != k) {
      if (extra_numbers.count(n) == 0) missingNumbers.push_back(n);
      n++;
    }
    return missingNumbers;
  }
};
