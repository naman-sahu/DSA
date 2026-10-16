#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum_sq = 0;
        long long sum_val = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        val %= MOD;
        long long len = (r - l + 1);
        
        // (x + v)^2 = x^2 + 2*v*x + v^2
        // sum_sq' = sum_sq + 2*v*sum_val + len * v^2
        long long add_sq = (2 * val % MOD * tree[node].sum_val) % MOD;
        long long val_sq_len = (val * val % MOD * len) % MOD;
        tree[node].sum_sq = (tree[node].sum_sq + add_sq + val_sq_len) % MOD;
        
        tree[node].sum_val = (tree[node].sum_val + len * val) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, tree[node].lazy);
            apply(node * 2 + 1, mid + 1, r, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void pull(int node) {
        tree[node].sum_sq = (tree[node * 2].sum_sq + tree[node * 2 + 1].sum_sq) % MOD;
        tree[node].sum_val = (tree[node * 2].sum_val + tree[node * 2 + 1].sum_val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        }
        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 5, Node());
        
        unordered_map<int, int> last_pos;
        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            
         
            update(1, 0, n - 1, prev + 1, i, 1);
            
          
            total_ans = (total_ans + tree[1].sum_sq) % MOD;
            
            last_pos[nums[i]] = i;
        }

        return (total_ans + MOD) % MOD;
    }
};