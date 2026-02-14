class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0;

        int left_max = height[l], right_max = height[r];

        while (l < r) {
            if (left_max > right_max) { // move the right pointer
                water += min(left_max, right_max) - height[r];

                r--;
                right_max = max(right_max, height[r]);
            } else {
                water += min(left_max, right_max) - height[l];

                l++;
                left_max = max(left_max, height[l]);
            }
        }

        return water;
    }
};