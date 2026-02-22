class Solution {
public:
    
    bool dfs(int node, vector<int>& color,
             vector<vector<int>>& graph) {
        
        for(int nbr : graph[node]) {
            
            if(color[nbr] == -1) {
                
                color[nbr] = 1 - color[node];
                
                if(!dfs(nbr, color, graph))
                    return false;
            }
            
            else if(color[nbr] == color[node]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++) {
            
            if(color[i] == -1) {
                
                color[i] = 0;
                
                if(!dfs(i, color, graph))
                    return false;
            }
        }
        
        return true;
    }
};
