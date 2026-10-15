class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for (auto& num : nums)
            dict[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& [j, v] : dict) {
            pq.push({v, j});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        result.reserve(k);
        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
