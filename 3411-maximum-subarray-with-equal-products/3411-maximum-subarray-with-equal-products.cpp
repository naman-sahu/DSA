class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            long long p = 1;
            int g = 0, l = 1;
            for (int j = i; j < n; j++) {
                p *= nums[j];
                // lcm <= 2520 and gcd <= 10, so lcm*gcd <= 25200.
                // Product only grows as the subarray extends, so we can stop.
                if (p > 25200) break;
                g = __gcd(g, nums[j]);
                l = l / __gcd(l, nums[j]) * nums[j];
                if (p == (long long)l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};