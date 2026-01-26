class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        int longest = 0;
        for (auto &num: nums){
            if (!mp[num]){
                // If not found will default to 0
                mp[num] = mp[num-1] + mp[num+1] + 1;

                // Update the tail and 
                mp[num - mp[num-1]] = mp[num];
                mp[num + mp[num+1]] = mp[num];

                longest = max(longest, mp[num]);
            }
        }

        return longest;
    }
};
