class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = -1e4, global_max = -1e4;

        for (auto &num: nums){
            curr_sum = max(num, curr_sum + num);
            global_max = max(global_max, curr_sum);
        }

        return global_max;
    }
};