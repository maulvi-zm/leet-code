class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<128> bit;

        int l = 0, longest = 0;
        for (int r = 0; r < s.size(); ++r) {
            int idx = s[r];

            while (bit.test(idx)) {
                bit.reset(s[l]);
                l++;
            }

            longest = max(longest, r - l + 1);

            bit.set(idx); 
        }

        return longest;
    }
};