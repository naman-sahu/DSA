class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // best[i] = minimum length of a valid subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefix = 0;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            
            // Check if there is a subarray with sum = target
            if (mp.count(prefix - target)) {
                int start = mp[prefix - target] + 1;
                int len = i - start + 1;
                
                // If a previous non-overlapping subarray exists
                if (start > 0 && best[start - 1] != INT_MAX) {
                    ans = min(ans, len + best[start - 1]);
                }
                
                // Store the minimum valid subarray length
                if (i == 0)
                    best[i] = len;
                else
                    best[i] = min(best[i - 1], len);
            } 
            else {
                if (i > 0)
                    best[i] = best[i - 1];
            }
            
            // Store earliest occurrence of prefix sum
            if (!mp.count(prefix)) {
                mp[prefix] = i;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};