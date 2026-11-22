
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        // First DFS: Find new parents
        function<void(int)> dfs1 = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];
            last[c] = u;

            if (u != 0) {
                newParent[u] = (prev != -1) ? prev : parent[u];
            }

            for (int v : adj[u]) {
                dfs1(v);
            }

            last[c] = prev;
        };

        dfs1(0);

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Second DFS: Calculate subtree sizes
        vector<int> ans(n, 1);

        function<int(int)> dfs2 = [&](int u) {
            for (int v : tree[u]) {
                ans[u] += dfs2(v);
            }
            return ans[u];
        };

        dfs2(0);

        return ans;
    }
};
