class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i], l = i + 1, r = n - 1;
            while (l < r) {
                if (l != i + 1 && nums[l] == nums[l-1]){
                    l++;
                    continue;
                }

                if (r != n - 1 && nums[r] == nums[r+1]){
                    r--;
                    continue;
                }

                int total = nums[l] + nums[r];
                if (total < target) {
                    l++;
                } else if (total > target) {
                    r--;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;
                }
            }
        }

        return result;
    }
};
