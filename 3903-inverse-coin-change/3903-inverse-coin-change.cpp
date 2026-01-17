class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> coins;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++){
            if (numWays[i] == 1){
                coins.push_back(i + 1);
                for (int j = n - 1; j > i && j - i -1 >= 0; j--){
                    if (visited[j][j-i-1]){
                        continue;
                    }

                    numWays[j] -= numWays[j-i-1];

                    // If you already reduce j by n, its mean you already visited (j-n) and n
                    visited[j][j-i-1] = true;
                    visited[j][i] = true;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (numWays[i] > 1 || numWays[i] < 0){
                return vector<int>();
            }
        }

        return coins;
    }
};