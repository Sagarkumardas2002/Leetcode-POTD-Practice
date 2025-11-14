class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        // Mark difference updates
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            diff[r1][c1] += 1;
            if (c2 + 1 < n) diff[r1][c2 + 1] -= 1;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= 1;
            if (r2 + 1 < n && c2 + 1 < n) diff[r2 + 1][c2 + 1] += 1;
        }

        // Build final matrix using prefix sums
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int top = (i > 0 ? ans[i - 1][j] : 0);
                int left = (j > 0 ? ans[i][j - 1] : 0);
                int diag = (i > 0 && j > 0 ? ans[i - 1][j - 1] : 0);

                ans[i][j] = diff[i][j] + top + left - diag;
            }
        }

        return ans;
    }
};