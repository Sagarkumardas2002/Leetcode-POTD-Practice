class Solution {
public:
    int countAllPath(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1)
            return 1;

        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = countAllPath(i + 1, j, m, n,dp) + countAllPath(i, j + 1, m, n,dp);

        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countAllPath(0, 0, m, n, dp);
    }
};