class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark visited land as water
        grid[i][j] = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
               grid[ni][nj] == 1) {

                dfs(ni, nj, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // 🔹 Step 1: Remove boundary-connected land

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) dfs(i, 0, grid);
            if(grid[i][m-1] == 1) dfs(i, m-1, grid);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) dfs(0, j, grid);
            if(grid[n-1][j] == 1) dfs(n-1, j, grid);
        }

        // 🔹 Step 2: Count remaining land

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
