class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> current_counter(26, 0);
        int longest = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            int idx = s[r] - 'A';
            current_counter[idx]++;

            int max_counter = *max_element(current_counter.begin(), current_counter.end());
            while ((r - l + 1) > max_counter + k && l < r) {
                --current_counter[s[l++] - 'A'];
                max_counter = *max_element(current_counter.begin(), current_counter.end());
            }

            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};
