// Number: 480
// Name: Sliding Window Median
// Tags: multiset, two heaps

// multiset, one pointer
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        vector<double> answer;
        auto mid = next(window.begin(), k / 2);
        for (int i = k;; ++i) {
            answer.push_back(((double)(*mid) +
                             *next(mid, k % 2 - 1)) * 0.5);
            if (i == nums.size())
                break;
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.find(nums[i - k]));
        }
        return answer;
    }
};

// two multiset
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> answer;
        multiset<int> lhs, rhs;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (nums[i - k] <= *lhs.rbegin())
                    lhs.erase(lhs.find(nums[i - k]));
                else
                    rhs.erase(rhs.find(nums[i - k]));
            }
            
            lhs.insert(nums[i]);
            rhs.insert(*lhs.rbegin());
            lhs.erase(prev(lhs.end()));
            if (lhs.size() < rhs.size()) {
                lhs.insert(*rhs.begin());
                rhs.erase(rhs.begin());
            }
            
            if (i >= k - 1) {
                if (k % 2 == 0) {
                    answer.push_back((
                        (double)*lhs.rbegin() + (double)*rhs.begin()) / 2);
                } else answer.push_back(*lhs.rbegin());
            }
        }
        return answer;
    }
};
