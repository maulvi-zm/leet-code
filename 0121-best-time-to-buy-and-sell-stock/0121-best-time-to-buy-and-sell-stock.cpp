class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int global_min = prices[0], global_max = prices[0];
        int res = 0;

        for (auto& num : prices) {
            if (num < global_min) {
                global_min = num;

                // reset the global max
                global_max = num;
            } else if (num > global_max) {
                global_max = num;
                res = max(res, global_max - global_min);
            }
        }

        return res;
    }
};