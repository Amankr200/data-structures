class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // Base case: end of either string
        if (i == s1.size() || j == s2.size()) return 0;

        // If already computed
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        else
            // Skip one char from either string
            return dp[i][j] = max(solve(i + 1, j, s1, s2, dp), solve(i, j + 1, s1, s2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, text1, text2, dp);
    }
};

