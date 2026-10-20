class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int need[128] = {};
        int missing = t.size();
        for (char c : t) need[c]++;

        int bestLen = INT_MAX, bestStarLen = -1;

        for (int l = 0, r = 0; r < s.size(); r++) {
            if (need[s[r]]-- > 0) missing--;

            while (missing == 0) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStarLen = l;
                }

                if (++need[s[l++]] > 0) missing++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStarLen, bestLen);
    }
};
