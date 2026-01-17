class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack

        for (int a : asteroids) {
            // Flag to track if the current asteroid 'a' survives
            bool destroyed = false;

            // Collision only happens if:
            // 1. Stack is not empty
            // 2. Current asteroid is moving left (< 0)
            // 3. Top of stack is moving right (> 0)
            while (!st.empty() && a < 0 && st.back() > 0) {
                if (st.back() < -a) {
                    st.pop_back();      // Top of stack is smaller, it explodes
                    continue;           // Current 'a' keeps moving left
                } else if (st.back() == -a) {
                    st.pop_back();      // Both are same size, both explode
                }
                destroyed = true;       // 'a' is destroyed
                break;
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }
        return st;
    }
};