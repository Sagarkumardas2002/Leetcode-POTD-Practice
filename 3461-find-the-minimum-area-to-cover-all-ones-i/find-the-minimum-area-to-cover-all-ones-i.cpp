class Solution {
public:
    int minimumArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int minRow = n;
        int maxRow = -1;

        int minCol = m;
        int maxCol = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {

                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};