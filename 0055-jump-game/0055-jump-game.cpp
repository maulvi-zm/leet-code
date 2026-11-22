class Solution {
public:
    bool canJump(vector<int>& nums) {
        int achievable = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i){
            if (achievable < i) return false;

            achievable = max(achievable, i + nums[i]);
        }

        return true;
    }
};