class Solution {
  public:
  
    /*
    Cycle Detection in Directed Graph (Input: Edge List)

    prerequisites[i] = {u, v}
    → Directed edge from u → v

    We first convert edge list into adjacency list.
    Then apply DFS with:
        vis[]     → visited array
        pathVis[] → recursion stack array

    If during DFS we reach a node already in recursion stack,
    then a BACK EDGE exists → cycle detected.
    */

    bool dfs(int node, vector<int>& vis,
             vector<int>& pathVis,
             vector<vector<int>>& adj) {
        
        vis[node] = 1;
        pathVis[node] = 1;  // mark node in current DFS path
        
        for(int nbr : adj[node]) {
            
            // If not visited
            if(!vis[nbr]) {
                if(dfs(nbr, vis, pathVis, adj))
                    return true;
            }
            
            // If visited AND still in recursion stack
            // → Back Edge → Cycle
            else if(pathVis[nbr] == 1) {
                return true;
            }
        }
        
        // Backtrack
        pathVis[node] = 0;
        
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Step 1: Convert Edge List → Adjacency List
        vector<vector<int>> adj(numCourses);
        
        for(auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);   // directed edge
        }
        
        // Step 2: Create visited & path arrays
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        
        // Step 3: Check all components
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj))
                    return false;
            }
        }
        
        return true;
    }
};
