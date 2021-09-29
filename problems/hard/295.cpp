// Number: 295
// Name: Find Median from Data Stream
// Tags: heap

//  insert - O(logN); find - O(1); space - O(N)
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (lhs_max.empty() && rhs_min.empty()) lhs_max.push(num);
        else if (!lhs_max.empty() && num <= lhs_max.top()) lhs_max.push(num);
        else rhs_min.push(num);
        rebalance();
    }
    
    double findMedian() {
        if (rhs_min.size() % 2 == lhs_max.size() % 2) {
            double mid_rhs = rhs_min.top();
            double mid_lhs = lhs_max.top();
            return (mid_rhs + mid_lhs) / 2;
        }
        return rhs_min.size() > lhs_max.size() ?  rhs_min.top() : lhs_max.top();
    }
    
private:
    void rebalance() {
        if (lhs_max.size() > 1 + rhs_min.size() ) {
            int lhs_max_top = lhs_max.top();
            lhs_max.pop();
            rhs_min.push(lhs_max_top);
        } else if (rhs_min.size() > 1 + lhs_max.size()) {
            int rhs_min_top = rhs_min.top();
            rhs_min.pop();
            lhs_max.push(rhs_min_top);
        }
    }
    
    priority_queue<int> lhs_max;
    priority_queue<int, vector<int>, greater<int>> rhs_min;
};

