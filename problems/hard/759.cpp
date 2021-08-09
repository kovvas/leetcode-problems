// Number: 759
// Name: Employee Free Time
// Tags: Intervals


// Time complexity NlogN
class Solution_0 {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int, int>> timeline;
        for (const auto& empl : schedule) {
            for (const auto& interval : empl) {
                timeline.push_back(make_pair(interval.start, 0));
                timeline.push_back(make_pair(interval.end, 1));
            }
        }
        sort(timeline.begin(), timeline.end(), 
            [](const auto& lhs, const auto& rhs){
                if (lhs.first == rhs.first) return lhs.second > rhs.second;
                return lhs.first < rhs.first;
            });
        vector<Interval> answer;
        int total_taken = 0;
        int curEnd = -1;
        for (int i = 0; i < timeline.size(); ++i) {
            if (i == 0) total_taken++;
            else if (total_taken == 0) {
                if (curEnd != timeline[i].first)
                    answer.push_back(Interval(curEnd, timeline[i].first));
                total_taken++;
            }
            else {
                if (timeline[i].second == 0) total_taken++;
                else {
                    total_taken--;
                    if (total_taken == 0)
                        curEnd = timeline[i].first;
                }
            }
        }
        return answer;
    }
};

