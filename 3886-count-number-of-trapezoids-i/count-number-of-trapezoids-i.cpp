class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> countY;

        // Count points at each y-level
        for (auto &p : points) {
            countY[p[1]]++;
        }

        long long S = 0;  
        long long Sq = 0;  

        for (auto &it : countY) {
            long long k = it.second;
            if (k >= 2) {
                long long H = (k * (k - 1) / 2) % MOD;  
                S = (S + H) % MOD;
                Sq = (Sq + (H * H) % MOD) % MOD;
            }
        }

        // final formula: (S^2 - Sq) / 2
        long long ans = ( (S * S % MOD - Sq + MOD) % MOD ) * ((MOD + 1) / 2) % MOD;
        return ans;
    }
};
