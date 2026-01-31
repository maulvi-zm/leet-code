class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int l = 0, r = 0;

        while (r < m && l < n){
            if (haystack[l] == needle[r]){
                l++;
                r++;
            } else {
                l -= (r - 1);
                r = 0;
            }
        }

        return r == m ? l - m : -1;
    }
};