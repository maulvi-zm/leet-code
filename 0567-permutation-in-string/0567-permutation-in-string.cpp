class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> cnt(26, 0);
        int matches = 0;

        auto update = [&](int c, int d) {
            if (cnt[c] == 0) matches--;
            cnt[c] += d;
            if (cnt[c] == 0) matches++;
        };

        for (char c : s1) cnt[c - 'a']++;
        for (int el : cnt)
            if (el == 0) matches++;

        for (int r = 0; r < s2.size(); r++) {
            update(s2[r] - 'a', -1);
            if (r >= n) update(s2[r - n] - 'a', +1);
            if (matches == 26) return true;
        }

        return false;
    }
};
