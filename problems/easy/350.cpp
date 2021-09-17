// Number: 350
// Name: Intersection of Two Arrays II
// Tags: hashmap

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nums1_data;
    for (const auto& x : nums1)
        nums1_data[x]++;
    vector<int> answer;
    for (const auto& x : nums2) {
        if (nums1_data.find(x) != nums1_data.end()) {
            if (nums1_data[x] != 0) {
                answer.push_back(x);
                nums1_data[x]--;
            }
        }
    }
    return answer;
}
