class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) != hash.end()){
                return vector<int>{hash[nums[i]], i};
            }

            hash[target - nums[i]] = i;
        }

        return vector<int>{};
    }
};