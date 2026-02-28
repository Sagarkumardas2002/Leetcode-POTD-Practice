class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitLen = 1,next = 2;

        for (int i = 1; i <= n; i++) {
            if(i==next){
                bitLen++;
                next*=2;
            }

            ans = ((ans << bitLen) + i) % MOD;
        }

        return (int)ans;
    }
};