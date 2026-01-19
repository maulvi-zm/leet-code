class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1, r = n - 1;

            int target = -nums[i];
            while (l < r){
                if (nums[l] + nums[r] == target){
                    result.push_back({nums[i], nums[l], nums[r]});

                    // Find different l and r
                    do {
                        l++;
                    } while (l < n && nums[l] == nums[l-1]);

                    do {
                        r--;
                    } while (r > 0 && nums[r] == nums[r+1]);

                } else if (nums[l] + nums[r] < target){
                    l++;
                } else {
                    r--;
                }

            }
        }

        return result;
    }
};