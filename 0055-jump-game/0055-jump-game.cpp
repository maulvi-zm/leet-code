class Solution {
public:
    bool canJump(vector<int>& nums) {
        constexpr size_t N = 10000;
        int n = nums.size();
        bitset<N> bt, window;

        bt.set(0);
        for (int i = 0; i < n; i++) {
            if (!bt.test(i)) continue;
            if (bt.test(n - 1)) break;

            bt |= (window.set() >> (N - min(n, nums[i]))) << i + 1;
        }

        return bt.test(n - 1);
    }
};
