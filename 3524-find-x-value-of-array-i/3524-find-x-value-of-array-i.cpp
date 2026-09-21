#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0); 
        
        for (int num : nums) {
            int v = num % k;
            vector<long long> next_dp(k, 0);
            
            // 1. A subarray containing only the current element
            next_dp[v] += 1;
            
            // 2. Extend all subarrays ending at the previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_r = (r * v) % k;
                    next_dp[new_r] += dp[r];
                }
            }
            
            dp = next_dp;
            
            // 3. Add counts of subarrays ending at the current index to the global answer
            for (int r = 0; r < k; ++r) {
                ans[r] += dp[r];
            }
        }
        
        return ans;
    }
};