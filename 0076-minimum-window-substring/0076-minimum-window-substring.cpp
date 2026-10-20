class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto ch : t) {
            mp[ch]--;
        }

        int isEnough = -mp.size();
        auto update = [&](char c, int d) {
            if (mp.count(c) == 0) return;

            if (mp[c] == 0 && d == -1)
                isEnough--;
            else if (mp[c] == -1 && d == 1)
                isEnough++;

            mp[c] += d;
        };

        int min_length = INT_MAX;
        pair<int, int> answer = {-1, -1};

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            update(s[r], +1);

            while (isEnough == 0) {
                if (r - l + 1 < min_length) {
                    min_length = r - l + 1;
                    answer.first = l;
                    answer.second = r;
                }

                update(s[l], -1);
                l++;
            }

        }

        if (min_length == INT_MAX) return "";
        return s.substr(answer.first, answer.second - answer.first + 1);
    }
};
