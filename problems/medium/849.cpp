// Number: 849
// Name: Maximize Distance to Closest Person
// Tags: array

// O(N), O(N)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> indexes;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) indexes.push_back(i);
        }
        int lhs = 0;
        int maxSize = 0;
        pair<int, int> curPair;
        for (int i = 0; i < indexes.size(); ++i) {
            int curSize = indexes[i] - lhs;
            if (maxSize < curSize) {
                maxSize = curSize;
                curPair = make_pair(lhs, indexes[i]);
            }
            lhs = indexes[i];
        }
        int curAnswer = (curPair.second - curPair.first) / 2;
        if (seats[seats.size() - 1] == 0) {
            if (curAnswer <= seats.size() - 1 - indexes[indexes.size() - 1])
                curAnswer = seats.size() - 1 - indexes[indexes.size() - 1];
        }
        if (seats[0] == 0) {
            if (curAnswer <= indexes[0])
                curAnswer = indexes[0];
        }
        return curAnswer;
    }
};
