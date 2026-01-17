class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);

        // Base case
        dp[0] = 1;

        // We loop using coin first to make sure we don't permute the solution (ex: 1,2 is different from 2,1)
        for (auto& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin] > INT_MAX ? INT_MAX : dp[i-coin];
            }
        }

        return dp[amount];
    }
};