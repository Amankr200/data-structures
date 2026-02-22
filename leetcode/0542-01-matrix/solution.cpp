class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // queue stores: {{row, col}, distance}
        queue<pair<pair<int,int>, int>> q;
        
        // 🔹 Push all 1's with distance 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // 🔹 BFS
        while(!q.empty()) {
            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            dist[x][y] = d;
            
            for(int k = 0; k < 4; k++) {
                
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
        
        return dist;
    }
};
