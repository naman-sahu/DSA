class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length
        if ((m + n - 1) % 2 == 1)
            return false;

        // dp[i][j] = possible balances at cell (i, j)
        vector<vector<bitset<205>>> dp(m, vector<bitset<205>>(n));

        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                // From top
                if (i > 0) {
                    for (int balance = 0; balance < 205; balance++) {
                        if (dp[i - 1][j][balance]) {
                            int newBalance = balance + change;

                            if (newBalance >= 0 && newBalance < 205)
                                dp[i][j][newBalance] = 1;
                        }
                    }
                }

                // From left
                if (j > 0) {
                    for (int balance = 0; balance < 205; balance++) {
                        if (dp[i][j - 1][balance]) {
                            int newBalance = balance + change;

                            if (newBalance >= 0 && newBalance < 205)
                                dp[i][j][newBalance] = 1;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};