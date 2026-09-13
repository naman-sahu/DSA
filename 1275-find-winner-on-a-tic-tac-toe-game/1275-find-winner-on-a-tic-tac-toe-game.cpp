class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3, 0));

        // 1 = A, 2 = B
        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];

            board[r][c] = (i % 2 == 0) ? 1 : 2;
        }

        // Check winner
        for (int player = 1; player <= 2; player++) {

            // Rows
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == player &&
                    board[i][1] == player &&
                    board[i][2] == player) {
                    return player == 1 ? "A" : "B";
                }
            }

            // Columns
            for (int j = 0; j < 3; j++) {
                if (board[0][j] == player &&
                    board[1][j] == player &&
                    board[2][j] == player) {
                    return player == 1 ? "A" : "B";
                }
            }

            // Main diagonal
            if (board[0][0] == player &&
                board[1][1] == player &&
                board[2][2] == player) {
                return player == 1 ? "A" : "B";
            }

            // Anti-diagonal
            if (board[0][2] == player &&
                board[1][1] == player &&
                board[2][0] == player) {
                return player == 1 ? "A" : "B";
            }
        }

        // Board completely filled
        if (moves.size() == 9)
            return "Draw";

        return "Pending";
    }
};