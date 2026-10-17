class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        int l = 0;
        for (int r = 0; r < prices.size(); r++) {
            int profit = prices[r] - prices[l];
            max_profit = max(max_profit, profit);

            if (prices[r] < prices[l]) {
                l = r;
            }
        }

        return max_profit;
    }
};
