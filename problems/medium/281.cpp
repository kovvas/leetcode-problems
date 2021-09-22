// Number: 281
// Name: Zigzag Iterator
// Tags: Design, queue

// O(1), O(K)
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            data.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty())
            data.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator lhs = data.front().first;
        vector<int>::iterator end = data.front().second;
        data.pop();
        if (lhs + 1 != end)
            data.push(make_pair(lhs + 1, end));
        return *lhs;
    }

    bool hasNext() {
        return !data.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> data;
};

