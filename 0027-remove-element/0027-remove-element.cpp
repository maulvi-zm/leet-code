class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = -1;

        for (auto& num : nums) {
            if (num != val) {
                nums[++l] = num;
            }
        }

        return l + 1;
    }
};