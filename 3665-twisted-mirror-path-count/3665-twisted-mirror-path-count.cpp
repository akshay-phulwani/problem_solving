class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<int,int>>> R(m, vector<pair<int,int>>(n, {-1,-1}));
        vector<vector<pair<int,int>>> D(m, vector<pair<int,int>>(n, {-1,-1}));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    R[i][j] = D[i][j] = {i, j};
                } else {
                    if (i + 1 < m)
                        R[i][j] = D[i+1][j];

                    if (j + 1 < n)
                        D[i][j] = R[i][j+1];
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                if (j + 1 < n) {
                    auto [x, y] = R[i][j+1];
                    if (x != -1)
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }

                if (i + 1 < m) {
                    auto [x, y] = D[i+1][j];
                    if (x != -1)
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
