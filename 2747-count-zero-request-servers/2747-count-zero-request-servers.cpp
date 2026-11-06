
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> ans(m);
        unordered_map<int, int> mp;

        int left = 0, right = 0;
        int active = 0;

        for (auto [t, idx] : q) {

            // Add requests within the current time window
            while (right < logs.size() && logs[right][1] <= t) {
                int server = logs[right][0];

                if (mp[server] == 0)
                    active++;

                mp[server]++;
                right++;
            }

            // Remove requests outside the current time window
            while (left < right && logs[left][1] < t - x) {
                int server = logs[left][0];

                mp[server]--;

                if (mp[server] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};

