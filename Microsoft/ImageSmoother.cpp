class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> adj(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1}, {0, 0}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ans = 0;
                int cnt = 0;

                for (auto [dx, dy] : directions) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        ans += grid[x][y];
                        cnt++;
                    }
                }

                adj[i][j] = ans / cnt;
            }
        }

        return adj;
    }
};
