// Number: 442
// Name: Find All Duplicates in an Array
// Tags: cyclic sort

// O(N) O(1) (modify input array)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else i++;
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1) answer.push_back(nums[i]);
        return answer;
    }
};
