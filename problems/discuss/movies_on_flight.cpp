// Name: Movies on flight
// Tags: sorting, two pointers

std::vector<int> movies_on_flight(std::vector<int> movie_duration, int d) {
    std::vector<std::vector<int>> data(d - 30 + 1);
    for (int i = 0; i < movie_duration.size(); ++i) {
        int curMovie = movie_duration[i];
        if (curMovie <= d - 30)
            data[curMovie].push_back(i);
    }
    int lhs = 0;
    int rhs = d - 30;
    int curMax = 0;
    int bestLhs = 0;
    int bestRhs = 0;
    while (lhs <= rhs) {
        if (data[lhs].empty()) {
            lhs++;
            continue;
        }
        if (data[rhs].empty()) {
            rhs--;
            continue;
        }
        if (lhs + rhs <= d - 30) {
            if (curMax < lhs + rhs) {
                curMax = lhs + rhs;
                bestLhs = lhs;
                bestRhs = rhs;
            } else if (curMax == lhs + rhs) {
                if (bestRhs < rhs) {
                    bestRhs = rhs;
                    bestLhs = lhs;
                } else if (bestRhs == rhs) {
                    bestLhs = std::max(bestLhs, lhs);
                }
            }
            lhs++;
        } else rhs--;
    }
    return {bestLhs, bestRhs};
}