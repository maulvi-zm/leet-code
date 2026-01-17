class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Dp i-th is the fewest coin to make up i amount
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (auto &coin: coins){
            if (coin <= amount){
                dp[coin] = 1;
            }
        }

        for (int i = 0; i <= amount; i++){

            // Loop the coin
            int min_coin = INT_MAX;
            for (auto &coin: coins){
                if (i - coin < 0){
                    continue;
                }

                if (dp[i - coin] != -1){
                    min_coin = min(min_coin, dp[i - coin] + 1);
                    dp[i] = min_coin;
                }
            }
        }

        return dp[amount];
    }
};