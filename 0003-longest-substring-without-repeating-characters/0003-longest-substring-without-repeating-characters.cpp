class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int max_length = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char curr = s[r];
            if (last_seen.count(curr) && last_seen[curr] >= l) {
                l = last_seen[curr] + 1;
            }

            last_seen[curr] = r;
            max_length = max(r - l + 1, max_length);
        }

        return max_length;
    }
};
