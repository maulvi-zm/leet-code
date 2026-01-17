class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, local_max = prices[0], local_min = prices[0];

        int curr_profit = 0;
        for (auto& num: prices){
            if (num < local_min || num < local_max){
                res += curr_profit;

                local_max = num;
                local_min = num;

                curr_profit = 0;
            } else if (num > local_max){
                local_max = num;

                curr_profit = local_max - local_min;
            }
        }

        if (curr_profit != 0){
            res += curr_profit;
        }

        return res;
    }
};