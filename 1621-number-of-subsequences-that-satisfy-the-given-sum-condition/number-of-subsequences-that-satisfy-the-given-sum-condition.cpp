class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> powof2(n);
        int MOD = 1e9 + 7;

        powof2[0] = 1;
        for (int i = 1; i < n; i++) {
            powof2[i] = (powof2[i - 1] * 2) % MOD;
        }

        int right = n - 1;
        int left = 0;
        int count = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + powof2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};