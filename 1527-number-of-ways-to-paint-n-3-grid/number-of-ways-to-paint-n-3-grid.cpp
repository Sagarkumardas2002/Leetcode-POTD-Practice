class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long abc = 6, aba = 6;

        for (int i = 2; i <= n; i++) {
            long long newABC = (2 * abc + 2 * aba) % MOD;
            long long newABA = (2 * abc + 3 * aba) % MOD;
            abc = newABC;
            aba = newABA;
        }

        return (abc + aba) % MOD;
    }
};
