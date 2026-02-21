class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
 
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first.first;
            int y = it.first.second;
            int t = it.second;

            ans = max(ans, t);

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 &&
                   nx < n && ny < m &&
                   grid[nx][ny] == 1 &&
                   !visited[nx][ny]) {

                    visited[nx][ny] = 1;
                    fresh--;
                    q.push({{nx, ny}, t + 1});
                }
            }
        }

        if(fresh > 0) return -1;
        return ans;
    }
};

