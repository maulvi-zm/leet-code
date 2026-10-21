class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(1e4 + 1, -1);
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        vector<int> ans(nums1.size(), 0);

        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if (mp[nums2[i]] != -1) {
                ans[mp[nums2[i]]] = st.empty() ? -1 : st.top();
            }

            st.push(nums2[i]);
        }

        return ans;
    }
};
