class Solution {
public:
    int recursion(int i, vector<int>& cost, vector<int>& dp) {
        if (i >= cost.size()) return 0;  // base case
        if (dp[i] != -1) return dp[i];   // already computed
        
        int oneStep = recursion(i + 1, cost, dp);
        int twoStep = recursion(i + 2, cost, dp);
        
        dp[i] = cost[i] + min(oneStep, twoStep);
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);  // initialize dp with -1
        return min(recursion(0, cost, dp), recursion(1, cost, dp));
    }
};

