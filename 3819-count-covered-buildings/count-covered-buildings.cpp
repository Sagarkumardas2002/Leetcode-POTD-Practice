class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();

        unordered_map<int, int> minInRow, maxInRow;
        unordered_map<int, int> minInCol, maxInCol;

        // Initialize maps
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (!minInRow.count(x)) minInRow[x] = y;
            minInRow[x] = min(minInRow[x], y);

            if (!maxInRow.count(x)) maxInRow[x] = y;
            maxInRow[x] = max(maxInRow[x], y);

            if (!minInCol.count(y)) minInCol[y] = x;
            minInCol[y] = min(minInCol[y], x);

            if (!maxInCol.count(y)) maxInCol[y] = x;
            maxInCol[y] = max(maxInCol[y], x);
        }

        int count = 0;

        // Check coverage
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            bool left  = y > minInRow[x];
            bool right = y < maxInRow[x];
            bool up    = x > minInCol[y];
            bool down  = x < maxInCol[y];

            if (left && right && up && down)
                count++;
        }

        return count;
    }
};
