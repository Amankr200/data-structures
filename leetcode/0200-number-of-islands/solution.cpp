class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // boundary check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') 
            return;

        // mark current cell as visited
        grid[i][j] = '0';

        // explore all 4 directions
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;              // found a new island
                    dfs(grid, i, j, m, n); // mark the entire island
                }
            }
        }
        return count;
    }
};
