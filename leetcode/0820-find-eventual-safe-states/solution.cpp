class Solution {
private:
    
    bool dfsCheck(int node,
                  vector<vector<int>>& graph,
                  vector<int>& vis,
                  vector<int>& pathVis,
                  vector<int>& check) {
        
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;   // assume unsafe
        
        for(int nbr : graph[node]) {
            
            // If not visited
            if(!vis[nbr]) {
                if(dfsCheck(nbr, graph, vis, pathVis, check))
                    return true;   // leads to cycle
            }
            
            // If visited and still in current path → cycle
            else if(pathVis[nbr] == 1) {
                return true;
            }
            
            // If already processed but unsafe
            else if(check[nbr] == 0) {
                return true;
            }
        }
        
        // No cycle reachable → safe
        check[node] = 1;
        pathVis[node] = 0;   // backtrack
        
        return false;
    }

public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);   // 1 = safe, 0 = unsafe
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            if(check[i] == 1)
                result.push_back(i);
        }
        
        return result;
    }
};
