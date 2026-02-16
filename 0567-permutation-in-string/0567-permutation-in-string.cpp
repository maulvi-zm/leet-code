class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_length = s1.size(), s2_length = s2.size();

        if (s1_length > s2_length){
            return false;
        }

        vector<int> correct(26, 0);
        for (auto &ch: s1){
            correct[ch - 'a']++;
        }

        vector<int> counter(26, 0);
        int l = 0;
        for (int i = 0; i < s2_length; i++){
            int idx = s2[i] - 'a';
            counter[idx]++;

            if (i - l + 1 > s1_length){
                int left_idx = s2[l] - 'a';
                counter[left_idx]--;
                l++;
            }

            if (counter == correct){
                return true;
            }
        }

        return false;
    }
};
