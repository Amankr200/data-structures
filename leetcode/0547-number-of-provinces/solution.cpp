class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for(int v : adj[node]) {
            if(!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        // convert matrix to adjacency list
        vector<vector<int>> adj(v);
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);
        int count = 0;

        // count connected components
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};

