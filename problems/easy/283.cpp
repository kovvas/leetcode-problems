// Number: 283
// Name: Move Zeroes
// Tags: array

//first come up with
void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1) {
        return;
    }
    int check = 0;
    int compare = check + 1;
    while (check < nums.size()) {
        compare = check + 1;
        if (nums[check] == 0) {
            for (int i = compare; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    swap(nums[check], nums[i]);
                    break;
                }
            }
        }
        check++;
    }
}
//good one
void moveZeroes(vector<int>& nums) {
    for(int i = 0, j = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            if (i != j) {
                nums[i] = 0;
            }
            j++;
        }
    }
}

// like previous but better to understand
void moveZeroes(vector<int>& nums) {
    int curZero = -1;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            curZero = i;
            break;
        }
    }
    if (curZero == -1) return;
    for (size_t i = curZero + 1; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[curZero++]);
            while (curZero != i) {
                if (nums[curZero] == 0)
                    break;
                curZero++;
            }
        }
    }
    return;
}
