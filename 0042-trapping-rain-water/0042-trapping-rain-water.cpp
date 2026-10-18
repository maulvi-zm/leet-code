class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_l = INT_MIN, max_r = INT_MIN;

        int trapped_water = 0;
        while (l < r) {
            max_l = max(height[l], max_l);
            max_r = max(height[r], max_r);

            if (max_l > max_r) {
                trapped_water += min(max_r, max_l) - height[r];
                r--;
            } else {
                trapped_water += min(max_r, max_l) - height[l];
                l++;
            }
        }

        return trapped_water;
    }
};
