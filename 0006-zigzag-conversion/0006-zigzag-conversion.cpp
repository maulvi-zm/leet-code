class Solution {
public:
    string convert(string s, int numRows) {
        int curr_row = 0;
        vector<string> rows(numRows, "");

        if (numRows == 1){
            return s;
        }

        int dir = 1;
        for (char c : s) {
            if (curr_row == numRows || curr_row == -1){
                dir *= -1;
                curr_row += 2 * dir;
            }

            rows[curr_row] += c;
            curr_row += dir;
        }

        string ans;
        for (auto row : rows) {
            ans += row;
        }

        return ans;
    }
};