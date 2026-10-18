class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1_counter(26, 0);
        for (auto& ch : s1) {
            int idx = ch - 'a';
            s1_counter[idx]++;
        }

        vector<int> curr_window_counter(26, 0);
        int window_size = s1.size();
        for (int i = 0; i < window_size - 1; i++) {
            int idx = s2[i] - 'a';
            curr_window_counter[idx]++;
        }

        int l = 0;
        for (int r = window_size - 1; r < s2.size(); r++) {
            int idx = s2[r] - 'a';
            curr_window_counter[idx]++;

            // Check if current window is a permutation of s1
            for (int i = 0; i < s1_counter.size(); i++) {
                if (s1_counter[i] != curr_window_counter[i]) {
                    break;
                }

                if (i == s1_counter.size() - 1) {
                    return true;
                }
            }

            idx = s2[l++] - 'a';
            curr_window_counter[idx]--;
        }

        return false;
    }
};
