class Solution {
public:
    // We can't use sliding window because the array it's not monotonic
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;

        int curr_sum = 0, ans = 0;

        // Base case: prefix sum of 0 appears once
        prefix_sum[0] = 1;
        
        for (auto &num : nums){
            curr_sum += num;

            // Note that: curr_sum - (curr_sum - k) = k
            // It's the basic of prefix_sum where sum(i, j) = prefix[i] - prefix[j-1]
            // So we just need to see if there's any subarray that has (curr_sum - k) value
            if (prefix_sum.find(curr_sum - k) != prefix_sum.end()){
                ans += prefix_sum[curr_sum - k];
            }

            prefix_sum[curr_sum]++;
        }

        return ans;
    }
};