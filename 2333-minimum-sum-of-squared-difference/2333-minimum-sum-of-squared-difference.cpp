
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0;
        int high = *max_element(diff.begin(), diff.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long used = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > low) {
                used += diff[i] - low;
                diff[i] = low;
            }
        }

        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == low && diff[i] > 0) {
                diff[i]--;
                remaining--;
            }
        }

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
