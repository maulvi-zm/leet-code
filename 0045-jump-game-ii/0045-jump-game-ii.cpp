class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);

        dp[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= nums[i] && i + j < n; j++){
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }

        return dp[n-1];
    }
};