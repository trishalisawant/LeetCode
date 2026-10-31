
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // memo[i][j][d]
        // d = 0: entered while moving right
        // d = 1: entered while moving down
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );

        function<int(int, int, int)> resolve =
        [&](int i, int j, int d) -> int {

            if (i >= m || j >= n)
                return -1;

            if (grid[i][j] == 0)
                return i * n + j;

            int &ans = memo[i][j][d];

            if (ans != -2)
                return ans;

            if (d == 0)
                ans = resolve(i + 1, j, 1);
            else
                ans = resolve(i, j + 1, 0);

            return ans;
        };

        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Try moving right
                if (j + 1 < n) {
                    int pos = resolve(i, j + 1, 0);

                    if (pos != -1) {
                        int r = pos / n;
                        int c = pos % n;

                        dp[r][c] =
                            (dp[r][c] + dp[i][j]) % MOD;
                    }
                }

                // Try moving down
                if (i + 1 < m) {
                    int pos = resolve(i + 1, j, 1);

                    if (pos != -1) {
                        int r = pos / n;
                        int c = pos % n;

                        dp[r][c] =
                            (dp[r][c] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
