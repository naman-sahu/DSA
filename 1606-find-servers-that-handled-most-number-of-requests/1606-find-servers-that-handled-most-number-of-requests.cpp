
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        // Initially all servers are available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish_time, server_id}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose tasks are completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // No server available
            if (available.empty()) {
                continue;
            }

            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
