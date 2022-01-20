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

// Time complexity NlogK
typedef pair<int, int> user_data;


class Comparator {
public:
    bool operator()(const pair<Interval, user_data>& lhs, const pair<Interval, user_data>& rhs) {
        return lhs.first.start > rhs.first.start;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<Interval, user_data>, vector<pair<Interval, user_data>>, Comparator> data;
        vector<Interval> answer;
        if (schedule.empty()) return answer;
        for (int i = 0; i < schedule.size(); ++i)
            data.push(make_pair(schedule[i][0], make_pair(i, 0)));
        auto prevInterval = data.top().first;
        while (!data.empty()) {
            auto dataTop = data.top();
            data.pop();
            if (dataTop.first.start > prevInterval.end) {
                answer.push_back(Interval(prevInterval.end, dataTop.first.start));
                prevInterval = dataTop.first;
            } else if (prevInterval.end < dataTop.first.end) prevInterval = dataTop.first;
            
            vector<Interval> employeeSchedule = schedule[dataTop.second.first];
            if (employeeSchedule.size() > dataTop.second.second + 1) {
                dataTop.second.second++;
                data.push(make_pair(employeeSchedule[dataTop.second.second], dataTop.second));
            }
        }
        return answer;
    }
};
