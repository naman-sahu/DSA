
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int NEG = -1000000000;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int gain = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    gain++;
                }
            }

            vector<int> buy(budget + 1, NEG);

            for (int cost = price; cost <= budget; cost++) {
                // First purchase of this item
                buy[cost] = max(buy[cost],
                                dp[cost - price] + gain);

                // Additional purchase of same item
                buy[cost] = max(buy[cost],
                                buy[cost - price] + 1);
            }

            for (int cost = 0; cost <= budget; cost++) {
                dp[cost] = max(dp[cost], buy[cost]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
