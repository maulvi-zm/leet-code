class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int global = 0, local_min = INT_MAX, local_max = INT_MIN;

        for (auto &price: prices){
            if (price < local_min){
                local_min = price;
                local_max = price;
            }

            local_max = max(price, local_max);
            global = max(local_max - local_min, global);
        }

        return global;
    }
};
