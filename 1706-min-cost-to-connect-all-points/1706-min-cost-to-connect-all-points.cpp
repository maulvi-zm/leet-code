class Solution {
private:
    int manhattanDistance(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<vector<int>> adj(n, vector<int>(n));
        vector<int> key(n, INT_MAX);
        vector<bool> inMST(n, false);
        int cost = 0;

        // This is the correct solution because every node can connect to every other node
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int distance = manhattanDistance(x1, y1, x2, y2);

                adj[i][j] = distance;
                adj[j][i] = distance;
            }
        }

        pq.push({0, 0});
        while (!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            cost += w;

            for (int v = 0; v < n; v++){
                int nw = adj[u][v];
                if (!inMST[v] && nw < key[v]){
                    key[v] = nw;
                    pq.push({nw, v});
                }
            }
        }

        return cost;
    }
};