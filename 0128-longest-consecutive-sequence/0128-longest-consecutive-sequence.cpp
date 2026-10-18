class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> size;

        int answer = 0;
        for (auto& num : nums) {
            if (size[num]) continue;

            size[num] = size[num - 1] + size[num + 1] + 1;
            size[num - size[num - 1]] = size[num];
            size[num + size[num + 1]] = size[num];

            answer = max(answer, size[num]);
        }

        return answer;
    }
};
