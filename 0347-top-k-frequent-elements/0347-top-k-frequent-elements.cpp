class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max_counter = INT_MIN;
        unordered_map<int, int> counter;
        for (auto &num: nums){
            counter[num]++;

            max_counter = max(max_counter, counter[num]);
        }

        vector<vector<int>> buckets(max_counter + 1, vector<int>());
        for (auto &[k, v]: counter){
            buckets[v].push_back(k);
        }

        vector<int> results;
        for (int i = max_counter; i > 0; --i){
            for (auto &num: buckets[i]){
                results.push_back(num);

                if (results.size() == k){
                    return results;
                }
            }
        }

        return results;
    }
};
