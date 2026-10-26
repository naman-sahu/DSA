
class Solution {
public:
    int n, m;
    
    long long dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }
        
        long long sum = grid[i][j];
        grid[i][j] = 0;  // Mark as visited
        
        sum += dfs(i + 1, j, grid);
        sum += dfs(i - 1, j, grid);
        sum += dfs(i, j + 1, grid);
        sum += dfs(i, j - 1, grid);
        
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    long long sum = dfs(i, j, grid);
                    
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
