class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const int NEG = -1e9;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, NEG))
        );

        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0];

            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (dp[i][j][k] == NEG) continue;

                    if (i + 1 < m) {
                        int val = coins[i + 1][j];

                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + val);

                        if (val < 0 && k < 2) {
                            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
                        }
                    }

                    if (j + 1 < n) {
                        int val = coins[i][j + 1];

                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + val);

                        if (val < 0 && k < 2) {
                            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k]);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};