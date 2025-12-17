class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 4;
        // flat[t]  : profit after t completed transactions, no position
        // longP[t] : profit after t completed transactions, holding long
        // shortP[t]: profit after t completed transactions, holding short

        vector<long long> flat(k + 1, NEG);
        vector<long long> longP(k + 1, NEG);
        vector<long long> shortP(k + 1, NEG);

        flat[0] = 0;

        for (int price : prices) {
            // snapshot to prevent same-day reuse
            vector<long long> prevFlat = flat;

            // close positions (complete a transaction)
            for (int t = k; t >= 1; --t) {
                if (longP[t - 1] != NEG)
                    flat[t] = max(flat[t], longP[t - 1] + price);
                if (shortP[t - 1] != NEG)
                    flat[t] = max(flat[t], shortP[t - 1] - price);
            }

            // open positions (must use previous day's flat)
            for (int t = 0; t <= k; ++t) {
                if (prevFlat[t] != NEG) {
                    longP[t] = max(longP[t], prevFlat[t] - price);
                    shortP[t] = max(shortP[t], prevFlat[t] + price);
                }
            }
        }

        return *max_element(flat.begin(), flat.end());
    }
};