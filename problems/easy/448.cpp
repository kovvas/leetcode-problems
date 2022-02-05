// Number: 448
// Name: Find All Numbers Disappeared in an Array
// Tags: array


// the same but shorter
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> missingNumbers;
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
        else i++;
    }
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != i + 1) missingNumbers.push_back(i + 1);
    return missingNumbers;
}

