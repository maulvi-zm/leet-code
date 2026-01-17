class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (auto &num: nums){
            vector<int> next_dp = dp;

            for (int s: dp){
                int next_sum = s + num;
                int remainder = next_sum % 3;
                next_dp[remainder] = max(next_sum, next_dp[remainder]);
            }

            dp = next_dp;
        }

        return dp[0];
    }
};