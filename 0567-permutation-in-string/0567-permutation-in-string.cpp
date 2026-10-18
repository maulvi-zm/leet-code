class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> cnt(26, 0);
        int matches = 0;

        auto add = [&](int c) {
            if (cnt[c] == 0) matches--;
            cnt[c]--;
            if (cnt[c] == 0) matches++;
        };

        auto remove = [&](int c) {
            if (cnt[c] == 0) matches--;
            cnt[c]++;
            if (cnt[c] == 0) matches++;
        };

        for (char c : s1) cnt[c - 'a']++;
        for (int el : cnt)
            if (el == 0) matches++;

        for (int r = 0; r < s2.size(); r++) {
            add(s2[r] - 'a');
            if (r >= n) remove(s2[r - n] - 'a');
            if (matches == 26) return true;
        }

        return false;
    }
};
