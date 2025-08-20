class Solution {
public:
    int n, m; // class-level

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t) {
        if(i >= n || j >= m) return 0;

        if(matrix[i][j] == 0) return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i, j+1, matrix, t);
        int down  = solve(i+1, j, matrix, t);
        int diag  = solve(i+1, j+1, matrix, t);

        return t[i][j] = 1 + min({right, down, diag});
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int result = 0;
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    result += solve(i, j, matrix, t);
                }
            }
        }
        return result;
    }
};
