class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        double windowSum = 0.0;
        for (int i = k; i < k + maxPts; i++) {
            windowSum += (i <= n) ? 1 : 0;
        }
        unordered_map<int, double> dp;
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = windowSum / maxPts;
            double remove = 0.0;
            if (i + maxPts <= n) {
                remove = dp.count(i + maxPts) ? dp[i + maxPts] : 1.0;
            }
            windowSum += dp[i] - remove;
        }
        return dp[0];
    }
};