class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9, col = 9;
        vector<int> rows(9, 0), cols(9, 0), squares(9, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;

                int bit = 1 << (ch - '0');
                int b = (i / 3) * 3 + j / 3;

                if (rows[i] & bit || cols[j] & bit || squares[b] & bit) return false;

                rows[i] |= bit;
                cols[j] |= bit;
                squares[b] |= bit;
            }
        }

        return true;
    }
};
