class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int left_max = height[l], right_max = height[r];

        int water = 0;
        while (l < r){
            if (left_max <= right_max){
                water += (left_max - height[l]);
                l++;

                left_max = max(height[l], left_max);
            } else {
                water += (right_max - height[r]);
                r--;
                
                right_max = max(height[r], right_max);
            }

            cout << l << " " << r << " " << water << endl;
        }

        return water;
    }
};