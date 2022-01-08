// Number: 1010
// Name: Pairs of Songs With Total Durations Divisible by 60
// Tags: Array

// O(N) O(60)
int numPairsDivisibleBy60(vector<int>& time) {
    const int duration = 60;
    unordered_map<int, vector<int>> data;
    for (int i = 0; i < (int)time.size(); ++i) {
        int div = time[i] % 60;
        if (data.find(div) != data.end()) data[div].push_back(i);
        else data[div] = {i};
    }
    int answer = 0;
    for (const auto& x : data) {
        if (x.first == duration / 2 || x.first == 0) answer += (int)x.second.size() * ((int)x.second.size() - 1) / 2;
        if (x.first < duration / 2) {
            int rest_part = duration - x.first;
            if (data.find(rest_part) != data.end()) {
                answer += (int)x.second.size() * (int)data[rest_part].size();
            }
        }
    }
    return answer;
}

int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> data(61);
    for (const auto& x : time) {
        int res = x % 60;
        data[res]++;
    }
    int answer = 0;
    answer += data[30] * (data[30] - 1) / 2;
    answer += data[0] * (data[0] - 1) / 2;
    for (const auto& x : time) {
        int temp = x % 60;
        if (temp < 30)
                answer += data[60 - temp];
    }
    return answer;
}
