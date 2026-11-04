class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        balance();
    }

    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            sumLow -= x;
            low.erase(it);
        } else {
            it = high.find(x);
            sumHigh -= x;
            high.erase(it);
        }

        balance();
    }

    void balance() {
        int target = (low.size() + high.size() + 1) / 2;

        while (low.size() > target) {
            auto it = prev(low.end());
            int x = *it;

            sumLow -= x;
            low.erase(it);

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < target && !high.empty()) {
            auto it = high.begin();
            int x = *it;

            sumHigh -= x;
            high.erase(it);

            low.insert(x);
            sumLow += x;
        }
    }

    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const ll INF = 1e18;

        vector<ll> cost(n - x + 1);

        // Step 1: Calculate cost of every window
        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Step 2: Dynamic Programming
        vector<ll> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = n - 1; i >= 0; i--) {
                // Skip current index
                curr[i] = curr[i + 1];

                // Select subarray of length x
                if (i + x <= n) {
                    curr[i] = min(
                        curr[i],
                        cost[i] + prev[i + x]
                    );
                }
            }

            prev = curr;
        }

        return prev[0];
    }
};