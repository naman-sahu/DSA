class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        
        // Precompute proper divisors for every possible substring length
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        
        // cost[i][j]: min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    int group_len = len / d;
                    // Check each of the d interleaved sequences
                    for (int offset = 0; offset < d; ++offset) {
                        int left = i + offset;
                        int right = i + offset + (group_len - 1) * d;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        
        // dp[i][p]: min changes to split prefix of length i into p semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (dp[m][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], dp[m][p - 1] + cost[m][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};