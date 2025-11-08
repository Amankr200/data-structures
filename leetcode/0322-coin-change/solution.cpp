class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
    // dp[i] = minimum coins to make amount i
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // base case: 0 coins needed to make 0 amount

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

};
