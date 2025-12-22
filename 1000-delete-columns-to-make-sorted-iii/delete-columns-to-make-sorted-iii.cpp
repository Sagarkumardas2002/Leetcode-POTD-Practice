class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = INT_MAX;
        vector<int> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                bool check = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][j] > strs[k][i]){
                        check = false;
                        break;
                    }
                }
                if (check) {
                    dp[i] = min(dp[i], dp[j] + (i - j - 1));
                }
            }
            ans = min(ans, dp[i] + m - 1 - i);
        }

        return ans;
    }
};