class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int s_counter[26] = {0}, t_counter[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            s_counter[idx]++;
        }

        for (int i = 0; i < t.size(); i++) {
            int idx = t[i] - 'a';
            t_counter[idx]++;
        }

        for (int i = 0; i < 26; i++) {
            if (s_counter[i] != t_counter[i]) {
                return false;
            }
        }

        return true;
    }
};
