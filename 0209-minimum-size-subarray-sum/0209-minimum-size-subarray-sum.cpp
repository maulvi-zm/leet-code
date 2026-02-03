class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, min_length = INT_MAX, curr = nums[0];

        int r = 0;
        while (r < n && l <= r) {
            if (curr >= target){
                min_length = min(min_length, r - l + 1);

                curr -= nums[l];
                l++;
            } else if (curr < target){
                r++;

                if (r >= n) break;
                curr += nums[r];
            } 
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};