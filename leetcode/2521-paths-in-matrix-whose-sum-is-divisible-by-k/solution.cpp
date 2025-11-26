class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

       
        vector<vector<int>> dp(n, vector<int>(k, 0));

   
        dp[0][grid[0][0] % k] = 1;
 
        for (int j = 1; j < n; j++) {
            for (int r = 0; r < k; r++) {
                if (dp[j-1][r]) {
                    int newRem = (r + grid[0][j]) % k;
                    dp[j][newRem] = (dp[j][newRem] + dp[j-1][r]) % MOD;
                }
            }
        }

   
        for (int i = 1; i < m; i++) {
            vector<vector<int>> newDp(n, vector<int>(k, 0));

            
            for (int r = 0; r < k; r++) {
                if (dp[0][r]) {
                    int newRem = (r + grid[i][0]) % k;
                    newDp[0][newRem] = (newDp[0][newRem] + dp[0][r]) % MOD;
                }
            }
 
            for (int j = 1; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (dp[j][r]) {  
                        int newRem = (r + grid[i][j]) % k;
                        newDp[j][newRem] = (newDp[j][newRem] + dp[j][r]) % MOD;
                    }
                    if (newDp[j-1][r]) {  
                        int newRem = (r + grid[i][j]) % k;
                        newDp[j][newRem] = (newDp[j][newRem] + newDp[j-1][r]) % MOD;
                    }
                }
            }

            dp = newDp;
        }

        return dp[n-1][0];  
    }
};

