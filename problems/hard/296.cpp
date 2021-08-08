// Number: 296
// Name: Best Meeting Point
// Tags: grid

// sorting; O(NlogN), O(N)
class Solution_1 {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<vector<int>> ones;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) ones.push_back({i, j});
            }
        }
        vector<int> meetPoint(2, 0);
        int size = ones.size() / 2;
        
        sort(ones.begin(), ones.end(), [](const auto& lhs, const auto& rhs){
            return lhs[1] < rhs[1];
        });
        meetPoint[1] = ones[size][1];
        
        sort(ones.begin(), ones.end(), [](const auto& lhs, const auto& rhs){
            return lhs[0] < rhs[0];
        });
        meetPoint[0] = ones[size][0];
        
        int answer = 0;
        for (const auto& x : ones) {
            answer += (abs(meetPoint[0] - x[0]) + abs(meetPoint[1] - x[1]));
        }
        cout << meetPoint[0] << " " << meetPoint[1] << endl;
        return answer;
    }
};

// using O(N)~O(NlogN) finding median
class Solution_2 {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<vector<int>> ones;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) ones.push_back({i, j});
            }
        }
        vector<int> meetPoint(2, 0);
        int m_i = ones.size() / 2;
        
        auto m = ones.begin() + m_i;
        nth_element(ones.begin(), m, ones.end(), [](const auto& lhs, const auto& rhs){
            return lhs[1] < rhs[1];
        });
        meetPoint[1] = ones[m_i][1];
        
        nth_element(ones.begin(), m, ones.end(), [](const auto& lhs, const auto& rhs){
            return lhs[0] < rhs[0];
        });
        meetPoint[0] = ones[m_i][0];
        
        int answer = 0;
        for (const auto& x : ones) {
            answer += (abs(meetPoint[0] - x[0]) + abs(meetPoint[1] - x[1]));
        }
        cout << meetPoint[0] << " " << meetPoint[1] << endl;
        return answer;
    }
};

// neat solution O(N)
class Solution_3 {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) rows.push_back(i);
            }
        }
        
        for (int i = 0; i < grid[0].size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 1) cols.push_back(i);
            }
        }
        
        vector<int> meetPoint(2, 0);

        meetPoint[0] = rows[rows.size() / 2];
        meetPoint[1] = cols[cols.size() / 2];
        
        int answer = 0;
        for (const auto& x : rows) {
            answer += (abs(meetPoint[0] - x));
        }
        for (const auto& x : cols) {
            answer += (abs(meetPoint[1] - x));
        }
        return answer;
    }
};

