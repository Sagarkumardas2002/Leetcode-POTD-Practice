class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;

        for (auto &sq : squares) {
            long double l = sq[2];
            totalArea += l * l;
        }

        long double low = 0, high = 1e18;
        long double half = totalArea / 2.0;

        for (int i = 0; i < 80; i++) { // enough for precision
            long double mid = (low + high) / 2.0;
            long double areaBelow = 0;

            for (auto &sq : squares) {
                long double y = sq[1];
                long double l = sq[2];

                if (mid <= y) {
                    continue;
                } else if (mid >= y + l) {
                    areaBelow += l * l;
                } else {
                    areaBelow += l * (mid - y);
                }
            }

            if (areaBelow < half)
                low = mid;
            else
                high = mid;
        }

        return (double)low;
    }
};
