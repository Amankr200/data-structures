class Solution {
private:
    void dfs(int x, int y,
             vector<vector<char>>& grid,
             vector<vector<int>>& visited,
             int n, int m) {

        visited[x][y] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 &&
               nx < n && ny < m &&
               grid[nx][ny] == '1' &&
               !visited[nx][ny]) {

                dfs(nx, ny, grid, visited, n, m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited, n, m);
                      count++;
                }
                }
        }
        return count;

    }
};
