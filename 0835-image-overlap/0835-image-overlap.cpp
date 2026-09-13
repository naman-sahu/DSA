class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> a, b;

        int n = img1.size();

        // Store positions of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> count;

        int ans = 0;

        // Try every possible relative shift
        for (auto p : a) {
            for (auto q : b) {
                int dx = p.first - q.first;
                int dy = p.second - q.second;

                count[{dx, dy}]++;

                ans = max(ans, count[{dx, dy}]);
            }
        }

        return ans;
    }
};