class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++){
            count += countPalindromSubstr(s, i, i);
            if (i + 1 < n) count += countPalindromSubstr(s, i, i + 1);
        }

        return count;
    }

    int countPalindromSubstr(string s, int l, int r){
        int length = s.size();
        int count = 0;

        while (l >= 0 && r < length){
            if (s[l] != s[r]){
                break;
            };

            count++;
            l--;
            r++;
        }

        return count;
    }
};