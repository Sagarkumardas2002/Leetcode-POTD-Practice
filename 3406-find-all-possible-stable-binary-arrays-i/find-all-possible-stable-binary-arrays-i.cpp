class Solution {
public:
    const int MOD = 1e9+7;
int zero, one, limit;
int dp[205][205][2][205];

int solve(int o, int z, int last, int streak){

    if(o==0 && z==0) return 1;

    int &res = dp[o][z][last][streak];
    if(res != -1) return res;

    long long ans = 0;

    if(z > 0){
        if(last == 0){
            if(streak < limit)
                ans += solve(o, z-1, 0, streak+1);
        } else {
            ans += solve(o, z-1, 0, 1);
        }
    }

    if(o > 0){
        if(last == 1){
            if(streak < limit)
                ans += solve(o-1, z, 1, streak+1);
        } else {
            ans += solve(o-1, z, 1, 1);
        }
    }

    return res = ans % MOD;
}

int numberOfStableArrays(int z, int o, int l) {

    zero = z;
    one = o;
    limit = l;

    memset(dp,-1,sizeof(dp));

    long long ans = 0;

    if(zero > 0)
        ans += solve(one, zero-1, 0, 1);

    if(one > 0)
        ans += solve(one-1, zero, 1, 1);

    return ans % MOD;
}
};