class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1) {
                result = result * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;

        vector<long long> fact(N + 1, 1);

        // Calculate factorials
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // C(N, 2*k) = N! / ((2*k)! * (N-2*k)!)
        long long ans = fact[N];

        ans = ans * power(fact[2 * k], MOD - 2) % MOD;

        ans = ans * power(fact[N - 2 * k], MOD - 2) % MOD;

        return ans;
    }
};