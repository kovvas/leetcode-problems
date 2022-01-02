// Number: 362
// Name: Design Hit Counter
// Tags: design

// keeping all timestamps
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        maxTimestamp = -1;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        maxTimestamp = timestamp;
        if (d_data.empty() || d_index_to_time[d_data.size() - 1] != timestamp) {
            d_data.push_back(1);
            d_index_to_time[d_data.size() - 1] = timestamp;
            d_time_to_index[timestamp] = d_data.size() - 1;
        } else d_data[d_time_to_index[timestamp]]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int answer = 0;
        int usingTimestamp = timestamp;
        if (d_data.empty()) return 0;
        if (d_time_to_index.find(usingTimestamp) == d_time_to_index.end())
            usingTimestamp = maxTimestamp;
            
        int curIndex = d_time_to_index[usingTimestamp];
        while (curIndex >= 0 && (timestamp - d_index_to_time[curIndex] < 300)) {
            answer += d_data[curIndex--];
        }
        return answer;
    }

private:
    vector<int> d_data;
    unordered_map<int, int> d_time_to_index;
    unordered_map<int, int> d_index_to_time;
    int maxTimestamp;
};

// keeping only 300 timestamps
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        data.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!data.empty()) {
            int diff = timestamp - data.front();
            if (diff >= 300) data.pop();
            else break;
        }
        return data.size();
    }

private:
    queue<int> data;
};

// clean solution for many hits per second
class HitCounter {
public:
    HitCounter() : hitsCounter(0) {
    }
    
    void hit(int timestamp) {
        hitsCounter++;
        if (data.empty() || data.back().first != timestamp) {
            data.push_back({timestamp, 1});
            while (!data.empty() && timestamp - data.front().first >= 300) {
                hitsCounter -= data.front().second;
                data.pop_front();
            }
        }
        else data.back().second++;
    }
    
    int getHits(int timestamp) {
        while (!data.empty() && timestamp - data.front().first >= 300) {
            hitsCounter -= data.front().second;
            data.pop_front();
        }
        return hitsCounter;
    }
private:
    deque<pair<int, int>> data;
    int hitsCounter;
};
