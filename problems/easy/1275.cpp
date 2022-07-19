// Number: 1275
// Name: Find Winner on a Tic Tac Toe Game
// Tags: Math

// O(M) O(N)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3);
        vector<int> cols(3);
        vector<int> diag(2);
        int curPlayer = 1;
        for (const auto& m : moves) {
            rows[m[0]] += curPlayer;
            cols[m[1]] += curPlayer;
            
            if (m[0] == m[1]) {
                diag[0] += curPlayer;
                if (m[0] == 1) diag[1] += curPlayer;
            }
            
            if (abs(m[0] - m[1]) == 2) diag[1] += curPlayer;
            
            curPlayer *= -1;
        }
        for (const auto& x : rows) {
            if (x == 3) return "A";
            if (x == -3) return "B";
        }
        for (const auto& x : cols) {
            if (x == 3) return "A";
            if (x == -3) return "B";
        }
        for (const auto& x : diag) {
            if (x == 3) return "A";
            if (x == -3) return "B";
        }
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};
