class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 3, 0);

        int max_amount = 0;
        for (int i = 3; i < n + 3; ++i){
            dp[i] += nums[i-3] + max(dp[i-2], dp[i-3]);
            max_amount = max(max_amount, dp[i]);
        }

        return max_amount;
    }
};


